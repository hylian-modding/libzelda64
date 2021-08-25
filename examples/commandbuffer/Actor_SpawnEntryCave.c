#include <libzelda64.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

struct Actor* Actor_SpawnEntryCave(struct ActorContext* actorCtx, struct ActorEntry* actorEntry, struct GlobalContext* globalCtx) {
    register CommandEvent* commandEvent = 0;
    struct Actor* actor = Actor_SpawnEntry(actorCtx, actorEntry, globalCtx);

    commandEvent = CommandBuffer_CommandEvent_GetCollision(actor, COMMANDEVENTTYPE_SPAWN, COMMANDEVENTTYPE_SPAWNTRANSITION);
    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_SPAWNENTRY;
        commandEvent->params.actor = actor;
    }
    else {
        commandEvent = CommandBuffer_CommandEvent_GetNext();

        if (commandEvent) {
            commandEvent->type = COMMANDEVENTTYPE_SPAWNENTRY;
            commandEvent->params.actor = actor;
            gCmdBuffer->eventCount++;
        }
    }

    return actor;
}

