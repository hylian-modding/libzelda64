#include <inttypes.h>
#include <libzelda64/lib/types/ActorContext.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/ObjectContext.h>
#include <libzelda64/lib/Flags.h>
#include <libzelda64/lib/ZeldaArena.h>
#include <libzelda64/lib/libc.h>
#include <libzelda64/lib/types/ActorId.h>
#include "Actor_CaveHelpers.h"

#ifdef GAME_OOT
// This function is unique to mm
Actor* Actor_SpawnWithParentAndCutsceneCave(ActorContext* actorCtx, GlobalContext* globalCtx, int16_t index, float x, float y, float z, int16_t rotX, int16_t rotY, int16_t rotZ, int32_t params, uint32_t cutscene, int32_t param_12, Actor* parent) {}
#elif defined GAME_MM
Actor* Actor_SpawnWithParentAndCutsceneCave(ActorContext* actorCtx, GlobalContext* globalCtx, int16_t index, float x, float y, float z, int16_t rotX, int16_t rotY, int16_t rotZ, int32_t params, uint32_t cutscene, int32_t param_12, Actor* parent) {
    register CommandEvent* commandEvent;
    Actor* actor;
    ActorInit* init;
    int32_t object;
    ActorOverlay* overlay;
    uint32_t tempSegment;

    if (actorCtx->total >= 255) {
        return NULL;
    }

    init = Actor_LoadOverlay(actorCtx, index);
    if (init == NULL) {
        return NULL;
    }

    object = Object_GetIndex(&globalCtx->objectCtx, init->objectId);
    if ((object < 0) || (init->category == ACTORCAT_ENEMY && Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num)) && (init->id != ACTOR_BOSS_05)) {
        overlay = &gActorOverlayTable[index];
        Actor_FreeOverlay(overlay);
        return NULL;
    }

    actor = (Actor*)ZeldaArena_Malloc(init->instanceSize);
    if (actor == NULL) {
        overlay = &gActorOverlayTable[index];
        Actor_FreeOverlay(overlay);
        return NULL;
    }

    overlay = &gActorOverlayTable[index];
    if (overlay->vramStart != 0) {
        overlay->nbLoaded += 1;
    }

    bzero(actor, init->instanceSize);
    actor->overlayEntry = overlay;
    actor->id = init->id;
    actor->flags = init->flags;
    if (init->id == ACTOR_EN_PART) {
        actor->objBankIndex = rotZ;
        rotZ = 0;
    }
    else {
        actor->objBankIndex = object;
    }

    actor->init = init->init;
    actor->destroy = init->destroy;
    actor->update = init->update;
    actor->draw = init->draw;

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
    actor->params = params;

    actor->cutscene = cutscene & 0x7F;
    if (actor->cutscene == 0x7F) {
        actor->cutscene = -1;
    }

    if (param_12) {
        actor->unk20 = param_12;
    } else {
        actor->unk20 = 0x3FF;
    }

    Actor_AddToCategory(actorCtx, actor, init->category);

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

    tempSegment = gSegments[6];
    Actor_Init(actor, globalCtx);
    gSegments[6] = tempSegment;
    return actor;
}
#endif
