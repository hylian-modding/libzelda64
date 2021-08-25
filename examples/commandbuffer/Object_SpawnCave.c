#include <inttypes.h>
#include <libzelda64/lib/DmaMgr.h>
#include <libzelda64/lib/types/ObjectContext.h>
#include <libzelda64/lib/types/RomFile.h>
#include "Actor_CaveHelpers.h"

#ifdef GAME_OOT
// For some reason, this crashes in 1.0!
int32_t Object_SpawnCave(ObjectContext* objectCtx, int16_t objectId) {
    register CommandEvent* commandEvent = 0;
    uint32_t size;

    commandEvent = CommandBuffer_CommandEvent_GetNext();
    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_OBJECTSPAWN;
        commandEvent->params.objSpawn.objectId = objectId;
    }

    objectCtx->status[objectCtx->num].id = objectId;
    size = gObjectTable[objectId].vromEnd - gObjectTable[objectId].vromStart;

    DmaMgr_SendRequest0(objectCtx->status[objectCtx->num].segment, gObjectTable[objectId].vromStart, size);

    if (objectCtx->num < OBJECT_EXCHANGE_BANK_MAX - 1) {
        objectCtx->status[objectCtx->num + 1].segment = (void*)ALIGN16((int32_t)objectCtx->status[objectCtx->num].segment + size);
    }

    objectCtx->num++;
    objectCtx->mainKeepNum = objectCtx->num;

    if (commandEvent) {
        commandEvent->params.objSpawn.objectCtxId = objectCtx->num = 1;
    }

    return objectCtx->num - 1;
}
#elif defined GAME_MM
// TODO?
int32_t Object_SpawnCave(ObjectContext* objectCtx, int16_t objectId) {}
#endif

