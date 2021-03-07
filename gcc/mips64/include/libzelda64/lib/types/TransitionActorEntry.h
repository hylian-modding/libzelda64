#ifndef TRANSITIONACTORENTRY_TYPE_H
#define TRANSITIONACTORENTRY_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct TransitionActorEntry_Side {
    int8_t room;
    int8_t effects;
};

typedef struct TransitionActorEntry {
    /* 0x00 */ TransitionActorEntry_Side sides[2];
    /* 0x04 */ int16_t id;
    /* 0x06 */ Vec3s pos;
    /* 0x0C */ int16_t rotY;
    /* 0x0E */ int16_t params;
} TransitionActorEntry; /* sizeof = 0x10 */


#endif

