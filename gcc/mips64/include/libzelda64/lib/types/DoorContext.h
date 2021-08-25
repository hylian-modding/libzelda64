#ifndef DOORCONTEXT_TYPE_H
#define DOORCONTEXT_TYPE_H

#include <inttypes.h>

typedef struct {
    /* 0x00 */ uint8_t numTransitionActors;
    /* 0x04 */ struct TransitionActorEntry* transitionActorList;
} DoorContext;

#endif

