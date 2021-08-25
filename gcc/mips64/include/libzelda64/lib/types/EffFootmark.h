#ifndef EFFFOOTMARK_TYPE_H
#define EFFFOOTMARK_TYPE_H

#include "MtxF.h"
#include "Vec3f.h"
#include <inttypes.h>

typedef struct EffFootmark {
    /* 0x00 */ MtxF displayMatrix;
    /* 0x40 */ struct Actor* actor;
    /* 0x44 */ Vec3f location;
    /* 0x50 */ uint8_t flags; // bit 0 - footmark fades out
    /* 0x51 */ uint8_t id;
    /* 0x52 */ uint8_t red;
    /* 0x53 */ uint8_t blue;
    /* 0x54 */ uint8_t green;
    /* 0x55 */ uint8_t pad55;
    /* 0x56 */ uint16_t alpha;
    /* 0x58 */ uint16_t alphaChange;
    /* 0x5A */ uint16_t size;
    /* 0x5C */ uint16_t fadeoutDelay;
    /* 0x5E */ uint16_t age;
} EffFootmark; /* sizeof = 0x60 */

#endif
