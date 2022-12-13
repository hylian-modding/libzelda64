#ifndef COLLIDERBUMP_TYPE_H
#define COLLIDERBUMP_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct ColliderBump {
    /* 0x00 */ uint32_t dmgFlags; // Bumper damage type flags.
    /* 0x04 */ uint8_t effect;    // Damage Effect (Knockback, Fire, etc.)
    /* 0x05 */ uint8_t defense;   // Damage Resistance
    /* 0x06 */ Vec3s hitPos;      // Point of contact
} ColliderBump;                   /* sizeof = 0x0C */

#endif
