#ifndef COLLISIONCONTEXT_TYPE_H
#define COLLISIONCONTEXT_TYPE_H

#include "Vec3f.h"
#include "Vec3i.h"
#include "SSNodeList.h"
#include "DynaCollisionContext.h"
#include <inttypes.h>

typedef struct CollisionContext {
    /* 0x0000 */ struct CollisionHeader* colHeader;
    /* 0x0004 */ Vec3f minBounds;
    /* 0x0010 */ Vec3f maxBounds;
    /* 0x001C */ Vec3i subdivAmount;
    /* 0x0028 */ Vec3f subdivLength;
    /* 0x0034 */ Vec3f subdivLengthInv;
    /* 0x0040 */ struct StaticLookup* lookupTbl;
    /* 0x0044 */ SSNodeList polyNodes;
    /* 0x0050 */ DynaCollisionContext dyna;
    /* 0x1460 */ uint32_t memSize;
} CollisionContext; /* sizeof = 0x1464 */

#endif

