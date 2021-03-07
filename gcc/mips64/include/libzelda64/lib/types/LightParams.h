#ifndef LIGHTPARAMS_TYPE_H
#define LIGHTPARAMS_TYPE_H

#include <inttypes.h>

typedef struct LightPoint {
    /* 0x00 */ int16_t x;
    /* 0x02 */ int16_t y;
    /* 0x04 */ int16_t z;
    /* 0x06 */ uint8_t color[3];
    /* 0x09 */ uint8_t drawGlow;
    /* 0x0A */ int16_t radius;
} LightPoint; /* sizeof = 0x0C */

typedef struct LightDirectional {
    /* 0x00 */ int8_t x;
    /* 0x01 */ int8_t y;
    /* 0x02 */ int8_t z;
    /* 0x03 */ uint8_t color[3];
} LightDirectional; /* sizeof = 0x06 */

typedef union LightParams {
    /* 0x00 */ LightPoint point;
    /* 0x00 */ LightDirectional dir;
} LightParams; /* sizeof = 0x0C */

#endif

