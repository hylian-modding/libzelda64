#include <inttypes.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/Actor.h>
#include <libzelda64/lib/types/ActorOverlay.h>
#include <libzelda64/lib/ObjectContext.h>
#include <libzelda64/lib/Flags.h>
#include <libzelda64/lib/ZeldaArena.h>
#include <libzelda64/lib/libc.h>
#include "Actor_CaveHelpers.h"

Actor* Actor_SpawnCave(struct ActorContext* actorCtx, struct GlobalContext* globalCtx, int16_t actorId, float posX, float posY, float posZ, int16_t rotX, int16_t rotY, int16_t rotZ, int16_t params) {
    register CommandEvent* commandEvent;
    Actor* actor = 0;
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

            if (overlayEntry->loadedRamAddr == 0) return 0;

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
        return 0;
    }

    actor = ZeldaArena_Malloc(actorInit->instanceSize);
    if (actor == 0) {
        Actor_FreeOverlay(overlayEntry);
        return 0;
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
    actor->home.pos.x = posX;
    actor->home.pos.y = posY;
    actor->home.pos.z = posZ;
    actor->home.rot.x = rotX;
    actor->home.rot.y = rotY;
    actor->home.rot.z = rotZ;
    actor->params = params;

    Actor_AddToCategory(&globalCtx->actorCtx, actor, actorInit->category);

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

    temp = gSegments[6];
    Actor_Init(actor, globalCtx);
    gSegments[6] = temp;

    return actor;
}