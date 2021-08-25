#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

// replace jr at 800B9744 in MM
void Actor_UpdateCave(struct Actor* actor, struct GlobalContext* globalCtx) {
    register CommandEvent* commandEvent = CommandBuffer_CommandEvent_GetCollision(actor, COMMANDEVENTTYPE_UPDATE, COMMANDEVENTTYPE_UPDATE);

    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_UPDATE;
        commandEvent->params.actor = actor;
    }
    else {
        commandEvent = CommandBuffer_CommandEvent_GetNext();

        if (commandEvent) {
            commandEvent->type = COMMANDEVENTTYPE_UPDATE;
            commandEvent->params.actor = actor;
            gCmdBuffer->eventCount++;
        }
    }

    actor->update(actor, globalCtx);

    return;
}

