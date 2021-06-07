#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"

void Actor_InitHook(struct Actor* actor, struct GlobalContext* globalCtx) {
    CommandActor* commandActor = CommandBuffer_CommandActor_GetNextCollision(actor, COMMANDACTORTYPE_INIT, COMMANDACTORTYPE_INIT);

    if (commandActor) {
        commandActor->type = COMMANDACTORTYPE_INIT;
        commandActor->actor = actor;
    }

    Actor_Init(actor, globalCtx);

    return;
}

