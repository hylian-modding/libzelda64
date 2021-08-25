#ifndef TRANSITIONACTORENTRY_TYPE_H
#define TRANSITIONACTORENTRY_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct {
    /* 0x00 */ int8_t room;
    /* 0x01 */ int8_t effects;
} TransitionActorEntry_Side; /* sizeof = 0x02 */

typedef struct TransitionActorEntry {
    /* 0x00 */ TransitionActorEntry_Side sides[2];
    /* 0x04 */ int16_t id;
    /* 0x06 */ Vec3s pos;
    /* 0x0C */ int16_t rotY;
    /* 0x0E */ int16_t params;
} TransitionActorEntry; /* sizeof = 0x10 */


#endif
