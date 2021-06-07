#ifndef ACTOR_HOOKHELPERS_H
#define ACTOR_HOOKHELPERS_H

#include <libzelda64/lib/Actor.h>
#include "commandbuffer.h"

extern uint32_t gSegments[];
asm("gSegments = 0x80120C38"); // may be wrong

extern ActorOverlay gActorOverlayTable[];
asm("gActorOverlayTable = 0x800E8530");

#define AM_FIELD_SIZE 0x27A0

__attribute__((always_inline)) inline CommandActor* CommandBuffer_CommandActor_GetNext() {
    uint32_t index;
    CommandActor* commandActor = 0;

    for (index = 0; index < COMMANDACTOR_MAX; index++) {
        if (cmdBuffer->commandActors[index].type == COMMANDACTORTYPE_NONE) {
            commandActor = &cmdBuffer->commandActors[index];
        }
    }

    return commandActor;
}

__attribute__((always_inline)) inline CommandActor* CommandBuffer_CommandActor_GetNextCollision(struct Actor* actor, uint32_t minType, uint32_t maxType) {
    uint32_t index;
    CommandActor* commandActor = 0;

    for (index = 0; index < COMMANDACTOR_MAX; index++) {
        if (cmdBuffer->commandActors[index].type >= minType && cmdBuffer->commandActors[index].type <= maxType) {
            if (cmdBuffer->commandActors[index].actor == actor) commandActor = &cmdBuffer->commandActors[index];
        }
    }

    if (commandActor == 0) commandActor = CommandBuffer_CommandActor_GetNext();

    return commandActor;
}

#endif

