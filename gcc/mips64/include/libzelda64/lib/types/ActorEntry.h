#ifndef ACTORENTRY_TYPE_H
#define ACTORENTRY_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct ActorEntry {
    /* 0x00 */ int16_t id;
    /* 0x02 */ Vec3s pos;
    /* 0x08 */ Vec3s rot;
    /* 0x0E */ int16_t params;
}; /* sizeof = 0x10 */

#endif
