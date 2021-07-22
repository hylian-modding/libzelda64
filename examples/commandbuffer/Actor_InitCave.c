#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

void Actor_InitCave(struct Actor* actor, struct GlobalContext* globalCtx) {
    CommandEvent* commandEvent = CommandBuffer_CommandEvent_GetNextCollision(actor, COMMANDEVENTTYPE_INIT, COMMANDEVENTTYPE_INIT);

    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_INIT;
        commandEvent->params.actor = actor;
        gCmdBuffer->eventCount++;
    }

    Actor_Init(actor, globalCtx);

    return;
}

