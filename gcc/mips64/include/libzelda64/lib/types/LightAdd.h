#ifndef LIGHTADD_TYPE_H
#define LIGHTADD_TYPE_H

#include <inttypes.h>

// TODO: Find decomp edition
typedef struct {
    /* 0x00 */ int16_t ambientCol[3];
    /* 0x06 */ int16_t diffuseCol[3];
    /* 0x0C */ int16_t fogCol[3];
    /* 0x12 */ short fogNear;
    /* 0x14 */ short fogFar;
} LightAdd; /* sizeof = 0x16 */

#endif
