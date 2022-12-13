#ifndef COLLIDERINFO_TYPE_H
#define COLLIDERINFO_TYPE_H

#include "ColliderBump.h"
#include "ColliderTouch.h"
#include <inttypes.h>

typedef struct ColliderInfo {
    /* 0x00 */ ColliderTouch toucher;          // Damage properties when acting as an AT collider
    /* 0x08 */ ColliderBump bumper;            // Damage properties when acting as an AC collider
    /* 0x14 */ uint8_t elemType;               // Affects sfx reaction when attacked by Link and hookability. Full purpose unknown.
    /* 0x15 */ uint8_t toucherFlags;           // Information flags for AT collisions
    /* 0x16 */ uint8_t bumperFlags;            // Information flags for AC collisions
    /* 0x17 */ uint8_t ocElemFlags;            // Information flags for OC collisions
    /* 0x18 */ struct Collider* atHit;         // object touching this element's AT collider
    /* 0x1C */ struct Collider* acHit;         // object touching this element's AC collider
    /* 0x20 */ struct ColliderInfo* atHitInfo; // element that hit the AT collider
    /* 0x24 */ struct ColliderInfo* acHitInfo; // element that hit the AC collider
} ColliderInfo;                                /* sizeof = 0x28 */

#endif
