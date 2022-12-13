#ifndef TRANSITIONTYPE_TYPE_H
#define TRANSITIONTYPE_TYPE_H

#include "Color_RGBA8_u32.h"
#include <inttypes.h>
#include <PR/gbi.h>

typedef struct {
    /* 0x000 */ uint8_t fadeType;
    /* 0x001 */ uint8_t isDone;
    /* 0x002 */ uint8_t fadeDirection;
    /* 0x004 */ Color_RGBA8_u32 fadeColor;
    /* 0x008 */ uint16_t fadeTimer;
} TransitionFade; /* sizeof = 0x0C */

typedef struct {
    /* 0x000 */ Color_RGBA8_u32 color;
    /* 0x004 */ Color_RGBA8_u32 envColor;
    /* 0x008 */ int32_t texX;
    /* 0x00C */ int32_t texY;
    /* 0x010 */ int32_t step;
    /* 0x014 */ uint8_t unk_14;
    /* 0x015 */ uint8_t typeColor;
    /* 0x016 */ uint8_t speed;
    /* 0x017 */ uint8_t effect;
    /* 0x018 */ uint8_t isDone;
    /* 0x019 */ uint8_t frame;
    /* 0x01A */ uint16_t normal;
    /* 0x020 */ Mtx projection;
    /* 0x060 */ Mtx lookAt;
    /* 0x0A0 */ char* texture;
    /* 0x0A8 */ Mtx modelView[2][3];
} TransitionCircle; /* sizeof = 0x228 */

typedef struct {
    /* 0x000 */ Color_RGBA8_u32 color;
    /* 0x004 */ float transPos;
    /* 0x008 */ float step;
    /* 0x00C */ int32_t state;
    /* 0x010 */ int32_t fadeDirection;
    /* 0x018 */ Mtx projection;
    /* 0x058 */ int32_t frame;
    /* 0x060 */ Mtx modelView[2][3];
} TransitionTriforce; /* sizeof = 0x1E0 */

typedef struct {
    /* 0x000 */ Color_RGBA8_u32 color;
    /* 0x004 */ Color_RGBA8_u32 envColor;
    /* 0x008 */ uint8_t direction;
    /* 0x009 */ uint8_t frame;
    /* 0x00A */ uint8_t isDone;
    /* 0x00C */ uint16_t texX;
    /* 0x00E */ uint16_t texY;
    /* 0x010 */ uint16_t normal;
    /* 0x018 */ Mtx projection;
    /* 0x058 */ Mtx lookAt;
    /* 0x098 */ Mtx modelView[2][3];
} TransitionWipe; /* sizeof = 0x218 */

typedef union TransitionType {
    /* 0x00 */ TransitionFade fade;
    /* 0x00 */ TransitionCircle circle;
    /* 0x00 */ TransitionTriforce triforce;
    /* 0x00 */ TransitionWipe wipe;
    /* 0x00 */ char data[0x228];
} TransitionType; /* sizeof = 0x228 */

#endif
