#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

// replace jr at 800B6968 in MM
void Actor_DestroyCave(struct Actor* actor, struct GlobalContext* globalCtx) {
    register CommandEvent* commandEvent = CommandBuffer_CommandEvent_GetCollision(actor, COMMANDEVENTTYPE_DESTROY, COMMANDEVENTTYPE_DESTROY);

    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_DESTROY;
        commandEvent->params.actor = actor;
    }
    else {
        commandEvent = CommandBuffer_CommandEvent_GetNext();

        if (commandEvent) {
            commandEvent->type = COMMANDEVENTTYPE_DESTROY;
            commandEvent->params.actor = actor;
            gCmdBuffer->eventCount++;
        }
    }

    actor->destroy(actor, globalCtx);

    return;
}
