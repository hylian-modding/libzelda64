#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

void Actor_DestroyCave(struct Actor* actor, struct GlobalContext* globalCtx) {
    CommandEvent* commandEvent = CommandBuffer_CommandEvent_GetNextCollision(actor, COMMANDEVENTTYPE_DESTROY, COMMANDEVENTTYPE_DESTROY);

    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_DESTROY;
        commandEvent->params.actor = actor;
        gCmdBuffer->eventCount++;
    }

    actor->destroy(actor, globalCtx);

    return;
}
