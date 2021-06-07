#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"

void Actor_UpdateHook(struct Actor* actor, struct GlobalContext* globalCtx) {
    CommandActor* commandActor = CommandBuffer_CommandActor_GetNextCollision(actor, COMMANDACTORTYPE_UPDATE, COMMANDACTORTYPE_UPDATE);

    if (commandActor) {
        commandActor->type = COMMANDACTORTYPE_UPDATE;
        commandActor->actor = actor;
    }

    actor->update(actor, globalCtx);

    return;
}

