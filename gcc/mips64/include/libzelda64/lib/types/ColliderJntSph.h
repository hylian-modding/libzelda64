#ifndef COLLIDERJNTSPH_TYPE_H
#define COLLIDERJNTSPH_TYPE_H

#include "Collider.h"
#include "ColliderJntSphElement.h"
#include <inttypes.h>

typedef struct {
    /* 0x00 */ Collider base;
    /* 0x18 */ int32_t count;
    /* 0x1C */ ColliderJntSphElement* elements;
} ColliderJntSph; /* sizeof = 0x20 */

#endif

