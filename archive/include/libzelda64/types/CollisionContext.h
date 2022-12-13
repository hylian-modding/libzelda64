#ifndef COLLISIONCONTEXT_TYPE_H
#define COLLISIONCONTEXT_TYPE_H

#include "DynaCollisionContext.h"
#include "SSNodeList.h"
#include "Vec3f.h"
#include "Vec3i.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
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

#else /* GAME_VERSION_1_0 */
#warning "CollisionContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct CollisionContext {
    /* 0x00 */ struct CollisionHeader* colHeader; // scene's static collision
    /* 0x04 */ Vec3f minBounds;                   // minimum coordinates of collision bounding box
    /* 0x10 */ Vec3f maxBounds;                   // maximum coordinates of collision bounding box
    /* 0x1C */ Vec3i subdivAmount;                // x, y, z subdivisions of the scene's static collision
    /* 0x28 */ Vec3f subdivLength;                // x, y, z subdivision worldspace lengths
    /* 0x34 */ Vec3f subdivLengthInv;             // inverse of subdivision length
    /* 0x40 */ struct StaticLookup* lookupTbl;    // 3d array of length subdivAmount
    /* 0x44 */ SSNodeList polyNodes;
    /* 0x50 */ DynaCollisionContext dyna;
    /* 0x1460 */ uint32_t memSize; // Size of all allocated memory plus CollisionContext
    /* 0x146C */ uint32_t unk146C;
} CollisionContext; // size = 0x1470
#endif                /* GAME_MM */

#endif
