#include <inttypes.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/types/ActorOverlay.h>
#include <libzelda64/lib/ObjectContext.h>
#include <libzelda64/lib/Flags.h>
#include <libzelda64/lib/ZeldaArena.h>
#include <libzelda64/lib/libc.h>
#include "Actor_CaveHelpers.h"

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