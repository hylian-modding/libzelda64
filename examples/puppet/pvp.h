#ifndef PVP_H
#define PVP_H

#include <inttypes.h>
#include <libzelda64/lib/Math.h>

enum {
    PVPDAMAGETYPE_NONE,
    PVPDAMAGETYPE_KNOCKBACK_WEAK,
    PVPDAMAGETYPE_KNOCKBACK_STRONG,
    PVPDAMAGETYPE_FIRE,
    PVPDAMAGETYPE_ICE,
    PVPDAMAGETYPE_LIGHT,
    PVPDAMAGETYPE_STUN,
    PVPDAMAGETYPE_BOTTLE,
    PVPDAMAGETYPE_COUNT
};

typedef struct {
    /* 0x00 */ uint8_t damageQueue;
    /* 0x02 */ uint8_t damageType;
    /* 0x02 */ int16_t damageAngle;
    /* 0x04 */ uint32_t damageFlags;
    /* 0x08 */ int32_t iframes;
} PvpContext; /* sizeof = 0x0C */

//#define IS_PVP

#endif

