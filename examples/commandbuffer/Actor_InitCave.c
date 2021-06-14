#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

void Actor_InitCave(struct Actor* actor, struct GlobalContext* globalCtx) {
    CommandActor* commandActor = CommandBuffer_CommandActor_GetNextCollision(actor, COMMANDACTORTYPE_INIT, COMMANDACTORTYPE_INIT);

    if (commandActor) {
        commandActor->type = COMMANDACTORTYPE_INIT;
        commandActor->actor = actor;
    }

    Actor_Init(actor, globalCtx);

    return;
}

