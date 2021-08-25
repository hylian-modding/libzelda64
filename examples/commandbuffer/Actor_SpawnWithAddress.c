#include <libzelda64.h>
#include "Actor_CaveHelpers.h"

#ifdef GAME_OOT
void Actor_SpawnWithAddress(GlobalContext* globalCtx, int16_t actorId, int16_t params, Vec3f* pos, Vec3s* rot, Actor* actor) {
    ActorInit* actorInit;
    ActorOverlay* overlayEntry;
    int32_t objBankIndex;
    uint32_t temp;
    uint32_t overlaySize;

    overlayEntry = &gActorOverlayTable[actorId];
    overlaySize = (uint32_t)overlayEntry->vramEnd - (uint32_t)overlayEntry->vramStart;

    if (overlayEntry->vramStart == 0) {
        actorInit = overlayEntry->initInfo;
    }
    else if (overlayEntry->loadedRamAddr == NULL) {
            if (overlayEntry->allocType & ALLOCTYPE_ABSOLUTE) {
                if (globalCtx->actorCtx.absoluteSpace == NULL) {
                    globalCtx->actorCtx.absoluteSpace = ZeldaArena_MallocR(AM_FIELD_SIZE);
                }

                overlayEntry->loadedRamAddr = globalCtx->actorCtx.absoluteSpace;
            }
            else if (overlayEntry->allocType & ALLOCTYPE_PERMANENT) {
                overlayEntry->loadedRamAddr = ZeldaArena_MallocR(overlaySize);
            }
            else {
                overlayEntry->loadedRamAddr = ZeldaArena_Malloc(overlaySize);
            }

            if (overlayEntry->loadedRamAddr == 0) {
                *((uint32_t*)&actor->id) = 0xDEAD0BAD;
                return;
            }

            Overlay_Load(overlayEntry->vromStart, overlayEntry->vromEnd, overlayEntry->vramStart, overlayEntry->vramEnd,
                         overlayEntry->loadedRamAddr);

            overlayEntry->nbLoaded = 0;
    }

    actorInit = (void*)(uint32_t)((overlayEntry->initInfo != NULL)
                ? (void*)((uint32_t)overlayEntry->initInfo -
                        (int32_t)((uint32_t)overlayEntry->vramStart - (uint32_t)overlayEntry->loadedRamAddr))
                : NULL);

    objBankIndex = Object_GetIndex(&globalCtx->objectCtx, actorInit->objectId);

    if ((objBankIndex < 0) || ((actorInit->category == ACTORCAT_ENEMY) && (Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num)))) {
        Actor_FreeOverlay(overlayEntry);
        *((uint32_t*)&actor->id) = 0xDEADDEAD;
        return;
    }

    overlayEntry->nbLoaded++;

    Lib_MemSet((uint8_t*)actor, actorInit->instanceSize, 0);
    actor->overlayEntry = overlayEntry;
    actor->id = actorInit->id;
    actor->flags = actorInit->flags;
    actor->objBankIndex = objBankIndex;
    actor->init = actorInit->init;
    actor->destroy = actorInit->destroy;
    actor->update = actorInit->update;
    actor->draw = actorInit->draw;
    actor->room = globalCtx->roomCtx.curRoom.num;
    actor->home.pos.x = pos->x;
    actor->home.pos.y = pos->y;
    actor->home.pos.z = pos->z;
    actor->home.rot.x = rot->x;
    actor->home.rot.y = rot->y;
    actor->home.rot.z = rot->z;
    actor->params = params;

    Actor_AddToCategory(&globalCtx->actorCtx, actor, actorInit->category);

    temp = gSegments[6];
    Actor_Init(actor, globalCtx);
    gSegments[6] = temp;

    return;
}
#elif defined GAME_MM
//return Actor_SpawnWithParentAndCutscene(actorCtx, globalCtx, index, x, y, z, rotX, rotY, rotZ, params, -1, parent->unk20, parent);
void Actor_SpawnWithAddress(ActorContext* actorCtx, GlobalContext* globalCtx, int16_t index, float x, float y, float z, int16_t rotX, int16_t rotY, int16_t rotZ, int32_t params, Actor* actor) {
    register CommandEvent* commandEvent;
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
    actor->room = globalCtx->roomCtx.curRoom.num;
    actor->home.pos.x = x;
    actor->home.pos.y = y;
    actor->home.pos.z = z;
    actor->home.rot.x = rotX;
    actor->home.rot.y = rotY;
    actor->home.rot.z = rotZ;
    actor->params = params;

    // I think this just ends up as F but I am too lazy to check
    actor->cutscene = ((uint32_t)-1) & 0x7F;
    if (actor->cutscene == 0x7F) {
        actor->cutscene = -1;
    }
    actor->unk20 = 0x3FF;

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

