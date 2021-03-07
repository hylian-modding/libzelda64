#ifndef COLLISIONCHECKINFO_TYPE_H
#define COLLISIONCHECKINFO_TYPE_H

#include "Vec3f.h"
#include <inttypes.h>

typedef struct CollisionCheckInfo {
    /* 0x00 */ struct DamageTable* damageTable;
    /* 0x04 */ Vec3f displacement; // Amount to correct velocity (0x5C) by when colliding into a body
    /* 0x10 */ int16_t cylRadius; // Used for various purposes
    /* 0x12 */ int16_t cylHeight; // Used for various purposes
    /* 0x14 */ int16_t cylYShift; // Unused. Purpose inferred from Cylinder16 and CollisionCheck_CylSideVsLineSeg
    /* 0x16 */ uint8_t mass; // Used to compute displacement for OC collisions
    /* 0x17 */ uint8_t health; // Note: some actors may use their own health variable instead of this one
    /* 0x18 */ uint8_t damage; // Amount to decrement health by
    /* 0x19 */ uint8_t damageEffect; // Stores what effect should occur when hit by a weapon
    /* 0x1A */ uint8_t atHitEffect; // Stores what effect should occur when AT connects with an AC
    /* 0x1B */ uint8_t acHitEffect; // Stores what effect should occur when AC is touched by an AT
} CollisionCheckInfo; /* sizeof = 0x1C */

#endif

