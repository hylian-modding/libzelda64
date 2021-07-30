#ifndef COLLIDERJNTSPHINIT_TYPE_H
#define COLLIDERJNTSPHINIT_TYPE_H

#include "ColliderInit.h"
#include <inttypes.h>

typedef struct {
    /* 0x00 */ ColliderInit base;
    /* 0x08 */ int32_t count;
    /* 0x0C */ struct ColliderJntSphElementInit* elements;
} ColliderJntSphInit; /* sizeof = 0x10 */

#endif

