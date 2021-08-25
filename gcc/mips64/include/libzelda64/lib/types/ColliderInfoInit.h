#ifndef COLLIDERINFOINIT_TYPE_H
#define COLLIDERINFOINIT_TYPE_H

#include "ColliderBumpInit.h"
#include "ColliderTouch.h"
#include <inttypes.h>

typedef struct ColliderInfoInit {
    /* 0x00 */ uint8_t elemType;        // Affects sfx reaction when attacked by Link and hookability. Full purpose unknown.
    /* 0x04 */ ColliderTouch toucher;   // Damage properties when acting as an AT collider
    /* 0x0C */ ColliderBumpInit bumper; // Damage properties when acting as an AC collider
    /* 0x14 */ uint8_t toucherFlags;    // Information flags for AT collisions
    /* 0x15 */ uint8_t bumperFlags;     // Information flags for AC collisions
    /* 0x16 */ uint8_t ocElemFlags;     // Information flags for OC collisions
} ColliderInfoInit;                     /* sizeof = 0x18 */

#endif
