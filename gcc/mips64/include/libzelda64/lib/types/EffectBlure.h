#ifndef BLURE_TYPE_H
#define BLURE_TYPE_H

#include "Color_RGBA8_u32.h"
#include "Vec3s.h"
#include <inttypes.h>

typedef struct EffectBlureElement {
    /* 0x00 */ int32_t state;
    /* 0x04 */ int32_t timer;
    /* 0x08 */ Vec3s p1;
    /* 0x0E */ Vec3s p2;
    /* 0x14 */ uint16_t flags;
} EffectBlureElement; /* sizeof = 0x18 */

typedef struct EffectBlure {
    /* 0x000 */ EffectBlureElement elements[16];
    /* 0x180 */ int32_t calcMode;
    /* 0x184 */ float mode4Param;
    /* 0x188 */ uint16_t flags;
    /* 0x18A */ int16_t addAngleChange;
    /* 0x18C */ int16_t addAngle;
    /* 0x18E */ Color_RGBA8_u32 p1StartColor;
    /* 0x192 */ Color_RGBA8_u32 p2StartColor;
    /* 0x196 */ Color_RGBA8_u32 p1EndColor;
    /* 0x19A */ Color_RGBA8_u32 p2EndColor;
    /* 0x19E */ uint8_t numElements; // "now_edge_num"
    /* 0x19F */ uint8_t elemDuration;
    /* 0x1A0 */ uint8_t unkFlag;
    /* 0x1A1 */ uint8_t drawMode;             // 0: simple; 1: simple with alt colors; 2+: smooth
    /* 0x1A2 */ Color_RGBA8_u32 altPrimColor; // used with drawMode 1
    /* 0x1A6 */ Color_RGBA8_u32 altEnvColor;  // used with drawMode 1
} EffectBlure;                                /* sizeof = 0x1AC */

typedef struct EffectBlureInit2 {
    /* 0x00 */ int32_t calcMode;
    /* 0x04 */ uint16_t flags;
    /* 0x06 */ int16_t addAngleChange;
    /* 0x08 */ uint8_t p1StartColor[4];
    /* 0x0C */ uint8_t p2StartColor[4];
    /* 0x10 */ uint8_t p1EndColor[4];
    /* 0x14 */ uint8_t p2EndColor[4];
    /* 0x18 */ uint8_t elemDuration;
    /* 0x19 */ uint8_t unkFlag;
    /* 0x1A */ uint8_t drawMode; // 0: simple; 1: simple with alt colors; 2+: smooth
    /* 0x1B */ uint8_t mode4Param;
    /* 0x1C */ Color_RGBA8_u32 altPrimColor; // used with drawMode 1
    /* 0x20 */ Color_RGBA8_u32 altEnvColor;  // used with drawMode 1
} EffectBlureInit2;                          /* sizeof = 0x24 */

#endif
