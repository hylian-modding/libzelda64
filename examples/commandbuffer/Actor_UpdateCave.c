#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

void Actor_UpdateCave(struct Actor* actor, struct GlobalContext* globalCtx) {
    CommandEvent* commandEvent = CommandBuffer_CommandEvent_GetNextCollision(actor, COMMANDEVENTTYPE_UPDATE, COMMANDEVENTTYPE_UPDATE);

    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_UPDATE;
        commandEvent->params.actor = actor;
        gCmdBuffer->eventCount++;
    }

    actor->update(actor, globalCtx);

    return;
}

