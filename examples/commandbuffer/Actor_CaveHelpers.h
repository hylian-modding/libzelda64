#ifndef ACTOR_HOOKHELPERS_H
#define ACTOR_HOOKHELPERS_H

#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"

extern uint32_t gSegments[];
asm("gSegments = 0x80120C38");

extern ActorOverlay gActorOverlayTable[];
asm("gActorOverlayTable = 0x800E8530");

#define AM_FIELD_SIZE 0x27A0

__attribute__((always_inline)) inline CommandEvent* CommandBuffer_CommandEvent_GetNext() {
    uint32_t index;
    CommandEvent* commandEvent = 0;

    //for (index = 0; index < gCmdBuffer->eventCount; index++) {
    //    if (gCmdBuffer->commandEvents[index].type == COMMANDEVENTTYPE_NONE) {
    //        commandEvent = &gCmdBuffer->commandEvents[index];
    //        break;
    //    }
    //}

    if (gCmdBuffer->eventCount < COMMANDEVENT_MAX) commandEvent = &gCmdBuffer->commandEvents[gCmdBuffer->eventCount];

    return commandEvent;
}

__attribute__((always_inline)) inline CommandEvent* CommandBuffer_CommandEvent_GetNextCollision(struct Actor* actor, uint32_t minType, uint32_t maxType) {
    uint32_t index;
    CommandEvent* commandEvent = 0;

    for (index = 0; index < gCmdBuffer->eventCount; index++) {
        if (gCmdBuffer->commandEvents[index].type >= minType && gCmdBuffer->commandEvents[index].type <= maxType) {
            if (gCmdBuffer->commandEvents[index].params.actor == actor) {
                commandEvent = &gCmdBuffer->commandEvents[index];
                break;
            }
        }
    }

    if (commandEvent == 0) commandEvent = CommandBuffer_CommandEvent_GetNext();

    return commandEvent;
}

#endif

