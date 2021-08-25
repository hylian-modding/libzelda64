#include <libzelda64.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

#ifdef GAME_OOT
struct Actor* Actor_SpawnTransitionActorCave(ActorContext* actorCtx, GlobalContext* globalCtx, int16_t actorId, float posX, float posY, float posZ, int16_t rotX, int16_t rotY, int16_t rotZ, int16_t params) {
    register CommandEvent* commandEvent = 0;
    struct Actor* actor = Actor_Spawn(actorCtx, globalCtx, actorId, posX, posY, posZ, rotX, rotY, rotZ, params);

    commandEvent = CommandBuffer_CommandEvent_GetCollision(actor, COMMANDEVENTTYPE_SPAWN, COMMANDEVENTTYPE_SPAWNTRANSITION);
    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_SPAWNTRANSITION;
        commandEvent->params.actor = actor;
    }
    else {
        commandEvent = CommandBuffer_CommandEvent_GetNext();

        if (commandEvent) {
            commandEvent->type = COMMANDEVENTTYPE_SPAWNTRANSITION;
            commandEvent->params.actor = actor;
            gCmdBuffer->eventCount++;
        }
    }

    return actor;
}
#elif defined GAME_MM
// whole function must be replaced in MM!
void Actor_SpawnTransitionActorsCave(GlobalContext* globalCtx, ActorContext* actorCtx) {
    register CommandEvent* commandEvent = 0;
    TransitionActorEntry* actorList = globalCtx->doorCtx.transitionActorList;
    Actor* actor;
    volatile uint32_t hexFloat = 0x43360B61; // avoiding rodata
    int32_t i;

    for (i = 0; i < globalCtx->doorCtx.numTransitionActors; actorList++, i++) {
        if (actorList->id >= 0 &&
           ((actorList->sides[0].room >= 0 && (actorList->sides[0].room == globalCtx->roomCtx.curRoom.num || actorList->sides[0].room == globalCtx->roomCtx.prevRoom.num)) ||
           (actorList->sides[1].room >= 0 && (actorList->sides[1].room == globalCtx->roomCtx.curRoom.num || actorList->sides[1].room == globalCtx->roomCtx.prevRoom.num)))) {
            int16_t params = ((actorList->rotY >> 7) & 0x1FF) * *((float*)&hexFloat);

            actor = Actor_SpawnWithParentAndCutscene(actorCtx, globalCtx, actorList->id & 0x1FFF, actorList->pos.x, actorList->pos.y, actorList->pos.z, 0, params, 0, (i << 0xA) + (actorList->params & 0x3FF), actorList->rotY & 0x7F, 0x3FF, NULL);
            if (actor != NULL) {
                actorList->id = -actorList->id;

                commandEvent = CommandBuffer_CommandEvent_GetCollision(actor, COMMANDEVENTTYPE_SPAWN, COMMANDEVENTTYPE_SPAWNTRANSITION);
                if (commandEvent) {
                    commandEvent->type = COMMANDEVENTTYPE_SPAWNTRANSITION;
                    commandEvent->params.actor = actor;
                }
                else {
                    commandEvent = CommandBuffer_CommandEvent_GetNext();

                    if (commandEvent) {
                        commandEvent->type = COMMANDEVENTTYPE_SPAWNTRANSITION;
                        commandEvent->params.actor = actor;
                        gCmdBuffer->eventCount++;
                    }
                }
            }
        }
    }
}
#endif

