#ifndef STANDARDLIMB_TYPE_H
#define STANDARDLIMB_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct StandardLimb {
    /* 0x00 */ Vec3s jointPos; // Root is position in model space, children are relative to parent
    /* 0x06 */ uint8_t child;
    /* 0x07 */ uint8_t sibling;
    /* 0x08 */ struct Gfx* dList;
} StandardLimb; /* size = 0xC */

#endif
