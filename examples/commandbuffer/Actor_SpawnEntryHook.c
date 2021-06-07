#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"

struct Actor* Actor_SpawnEntryHook(struct ActorContext* actorCtx, struct ActorEntry* actorEntry, struct GlobalContext* globalCtx) {
    CommandActor* commandActor = 0;
    struct Actor* actor = Actor_SpawnEntry(actorCtx, actorEntry, globalCtx);

    commandActor = CommandBuffer_CommandActor_GetNextCollision(actor, COMMANDACTORTYPE_SPAWN, COMMANDACTORTYPE_SPAWNTRANSITION);
    if (commandActor) {
        commandActor->type = COMMANDACTORTYPE_SPAWNENTRY;
        commandActor->actor = actor;
    }

    return actor;
}

