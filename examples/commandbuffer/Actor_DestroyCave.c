#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

void Actor_DestroyCave(struct Actor* actor, struct GlobalContext* globalCtx) {
    CommandActor* commandActor = CommandBuffer_CommandActor_GetNextCollision(actor, COMMANDACTORTYPE_DESTROY, COMMANDACTORTYPE_DESTROY);

    if (commandActor) {
        commandActor->type = COMMANDACTORTYPE_DESTROY;
        commandActor->actor = actor;
    }

    actor->destroy(actor, globalCtx);

    return;
}
