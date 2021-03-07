#ifndef BGACTOR_TYPE_H
#define BHACTOR_TYPE_H

#include "DynaLookup.h"
#include "ScaleRotPos.h"
#include "Sphere16.h"
#include <inttypes.h>

typedef struct BgActor {
    /* 0x00 */ struct Actor* actor;
    /* 0x04 */ struct CollisionHeader* colHeader;
    /* 0x08 */ DynaLookup dynaLookup;
    /* 0x10 */ uint16_t vtxStartIndex;
    /* 0x14 */ ScaleRotPos prevTransform;
    /* 0x34 */ ScaleRotPos curTransform;
    /* 0x54 */ Sphere16 boundingSphere;
    /* 0x5C */ float minY;
    /* 0x60 */ float maxY;
} BgActor; /* sizeof = 0x64 */

#endif

