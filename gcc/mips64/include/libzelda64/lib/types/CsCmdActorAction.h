#ifndef CSCMDACTORACTION_TYPE_H
#define CSCMDACTORACTION_TYPE_H

#include "Vec3s.h"
#include "Vec3i.h"
#include <inttypes.h>

typedef struct CsCmdActorAction {
    /* 0x00 */ uint16_t action;
    /* 0x02 */ uint16_t startFrame;
    /* 0x04 */ uint16_t endFrame;
    union {
        /* 0x06 */ Vec3s rot;
        /* 0x06 */ Vec3us urot;
    };
    /* 0x0C */ Vec3i startPos;
    /* 0x18 */ Vec3i endPos;
    /* 0x24 */ Vec3i normal;
} CsCmdActorAction; /* sizeof = 0x30 */

#endif

