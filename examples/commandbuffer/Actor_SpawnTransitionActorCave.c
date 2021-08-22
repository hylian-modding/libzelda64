#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

struct Actor* Actor_SpawnTransitionActorCave(struct ActorContext* actorCtx, struct GlobalContext* globalCtx, int16_t actorId, float posX, float posY, float posZ, int16_t rotX, int16_t rotY, int16_t rotZ, int16_t params) {
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

