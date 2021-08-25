#include <libzelda64.h>
#include "commandbuffer.h"
#include "Actor_CaveHelpers.h"

void Actor_InitCave(struct Actor* actor, struct GlobalContext* globalCtx) {
    register CommandEvent* commandEvent = CommandBuffer_CommandEvent_GetCollision(actor, COMMANDEVENTTYPE_INIT, COMMANDEVENTTYPE_INIT);

    if (commandEvent) {
        commandEvent->type = COMMANDEVENTTYPE_INIT;
        commandEvent->params.actor = actor;
    }
    else {
        commandEvent = CommandBuffer_CommandEvent_GetNext();

        if (commandEvent) {
            commandEvent->type = COMMANDEVENTTYPE_INIT;
            commandEvent->params.actor = actor;
            gCmdBuffer->eventCount++;
        }
    }

    Actor_Init(actor, globalCtx);

    return;
}

