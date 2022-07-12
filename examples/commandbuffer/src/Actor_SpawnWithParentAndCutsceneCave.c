#include <libzelda64.h>
#include "Actor_CaveHelpers.h"

#ifdef GAME_OOT
// This function is unique to mm
Actor* Actor_SpawnWithParentAndCutsceneCave(ActorContext* actorCtx, GlobalContext* globalCtx, int16_t index, float x, float y, float z, int16_t rotX, int16_t rotY, int16_t rotZ, int32_t params, uint32_t cutscene, int32_t param_12, Actor* parent) {}
#elif defined GAME_MM
Actor* Actor_SpawnWithParentAndCutsceneCave(ActorContext* actorCtx, GlobalContext* globalCtx, int16_t index, float x, float y, float z, int16_t rotX, int16_t rotY, int16_t rotZ, int32_t params, uint32_t cutscene, int32_t param_12, Actor* parent) {
    register CommandEvent* commandEvent;
    Actor* actor;
    ActorInit* actorInit;
    int32_t objBankIndex;
    uint32_t segmentAux;
    ActorOverlay* overlayEntry;

    if (actorCtx->total >= 0xFF) {
        return NULL;
    }

    actorInit = Actor_LoadOverlay(actorCtx, index);
    if (actorInit == NULL) {
        return NULL;
    }

    objBankIndex = Object_GetIndex(&globalCtx->objectCtx, actorInit->objectId);
    if ((objBankIndex < 0) || ((actorInit->category == ACTORCAT_ENEMY) && ((Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num) != 0)) && (actorInit->id != ACTOR_BOSS_05))) {
        Actor_FreeOverlay(&gActorOverlayTable[index]);
        return NULL;
    }

    actor = ZeldaArena_Malloc(actorInit->instanceSize);
    if (actor == NULL) {
        Actor_FreeOverlay(&gActorOverlayTable[index]);
        return NULL;
    }

    overlayEntry = &gActorOverlayTable[index];
    if (overlayEntry->vramStart != 0) {
        overlayEntry->nbLoaded++;
    }

    bzero(actor, actorInit->instanceSize);
    actor->overlayEntry = overlayEntry;
    actor->id = actorInit->id;
    actor->flags = actorInit->flags;

    if (actorInit->id == ACTOR_EN_PART) {
        actor->objBankIndex = rotZ;
        rotZ = 0;
    }
    else {
        actor->objBankIndex = objBankIndex;
    }

    actor->init = actorInit->init;
    actor->destroy = actorInit->destroy;
    actor->update = actorInit->update;
    actor->draw = actorInit->draw;

    if (parent != NULL) {
        actor->room = parent->room;
        actor->parent = parent;
        parent->child = actor;
    }
    else {
        actor->room = globalCtx->roomCtx.curRoom.num;
    }

    actor->home.pos.x = x;
    actor->home.pos.y = y;
    actor->home.pos.z = z;
    actor->home.rot.x = rotX;
    actor->home.rot.y = rotY;
    actor->home.rot.z = rotZ;
    actor->params = params & 0xFFFF;
    actor->cutscene = (cutscene & 0x7F);

    if (actor->cutscene == 0x7F) {
        actor->cutscene = -1;
    }

    if (param_12 != 0) {
        actor->unk20 = param_12;
    }
    else {
        actor->unk20 = 0x3FF;
    }

    Actor_AddToCategory(actorCtx, actor, actorInit->category);

    commandEvent = CommandBuffer_CommandEvent_GetCollision(actor, COMMANDEVENTTYPE_SPAWN, COMMANDEVENTTYPE_SPAWNTRANSITION);
    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_SPAWN;
        commandEvent->params.actor = actor;
    }
    else {
        commandEvent = CommandBuffer_CommandEvent_GetNext();

        if (commandEvent) {
            commandEvent->type = COMMANDEVENTTYPE_SPAWN;
            commandEvent->params.actor = actor;
            gCmdBuffer->eventCount++;
        }
    }

    segmentAux = gSegments[6];
    Actor_Init(actor, globalCtx);
    gSegments[6] = segmentAux;

    return actor;
}
#endif
