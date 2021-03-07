#ifndef COLLIDERBUMPINIT_TYPE_H
#define COLLIDERBUMPINIT_TYPE_H

#include <inttypes.h>

typedef struct ColliderBumpInit {
    /* 0x00 */ uint32_t dmgFlags; // Bumper exclusion mask
    /* 0x04 */ uint8_t effect; // Damage Effect (Knockback, Fire, etc.)
    /* 0x05 */ uint8_t defense; // Damage Resistance
} ColliderBumpInit; /* size = 0x08 */

#endif

