#ifndef COLLIDERTOUCH_TYPE_H
#define COLLIDERTOUCH_TYPE_H

#include <inttypes.h>

typedef struct ColliderTouch {
    /* 0x00 */ uint32_t dmgFlags; // Toucher damage type flags.
    /* 0x04 */ uint8_t effect; // Damage Effect (Knockback, Fire, etc.)
    /* 0x05 */ uint8_t damage; // Damage or Stun Timer
} ColliderTouch; /* sizeof = 0x08 */

#endif

