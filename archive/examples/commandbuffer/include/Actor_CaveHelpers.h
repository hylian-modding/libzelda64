#ifndef ACTOR_HOOKHELPERS_H
#define ACTOR_HOOKHELPERS_H

#include <libzelda64.h>
#include "commandbuffer.h"

#define AM_FIELD_SIZE 0x27A0

__attribute__((always_inline)) inline CommandEvent* CommandBuffer_CommandEvent_GetNext() {
    uint32_t index;
    register CommandEvent* commandEvent = 0;
    register CommandBuffer* cmdBuffer = gCmdBuffer;

    if (cmdBuffer->eventCount < COMMANDEVENT_MAX) commandEvent = &cmdBuffer->commandEvents[cmdBuffer->eventCount];

    return commandEvent;
}

__attribute__((always_inline)) inline CommandEvent* CommandBuffer_CommandEvent_GetCollision(struct Actor* actor, uint32_t minType, uint32_t maxType) {
    uint32_t index;
    register CommandEvent* commandEvent = 0;
    register CommandBuffer* cmdBuffer = gCmdBuffer;

    // old method, slow, causes lag
#ifdef OLD_CE_GETNEXTCOLLISION
    for (index = 0; index < cmdBuffer->eventCount; index++) {
        if (cmdBuffer->commandEvents[index].type >= minType && cmdBuffer->commandEvents[index].type <= maxType) {
            if (cmdBuffer->commandEvents[index].params.actor == actor) {
                commandEvent = &cmdBuffer->commandEvents[index];
                break;
            }
        }
    }
#endif

    // new method, faster, assumes prior command would have been the command we are hijacking
    if (cmdBuffer->commandEvents[cmdBuffer->eventCount - 1].type >= minType && cmdBuffer->commandEvents[cmdBuffer->eventCount - 1].type <= maxType) {
        if (cmdBuffer->commandEvents[index].params.actor == actor) {
            commandEvent = &cmdBuffer->commandEvents[index];
        }
    }

    return commandEvent;
}

#endif

