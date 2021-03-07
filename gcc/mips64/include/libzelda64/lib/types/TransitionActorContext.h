#ifndef TRANSITIONACTORCONTEXT_TYPE_H
#define TRANSITIONACTORCONTEXT_TYPE_H

#include <inttypes.h>

typedef struct TransitionActorContext {
    /* 0x00 */ uint8_t nbTransitionActors;
    /* 0x04 */ struct TransitionActorEntry* transitionActorList;
} TransitionActorContext; /* sizeof = 0x08 */


#endif
