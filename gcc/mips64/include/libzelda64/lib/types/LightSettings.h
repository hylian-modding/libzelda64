#ifndef LIGHTSETTINGS_TYPE_H
#define LIGHTSETTINGS_TYPE_H

#include <inttypes.h>

typedef struct LightSettings {
    /* 0x00 */ uint8_t ambientClrR;
    /* 0x01 */ uint8_t ambientClrG;
    /* 0x02 */ uint8_t ambientClrB;
    /* 0x03 */ uint8_t diffuseClrA_R;
    /* 0x04 */ uint8_t diffuseClrA_G;
    /* 0x05 */ uint8_t diffuseClrA_B;
    /* 0x06 */ uint8_t diffuseDirA_X;
    /* 0x07 */ uint8_t diffuseDirA_Y;
    /* 0x08 */ uint8_t diffuseDirA_Z;
    /* 0x09 */ uint8_t diffuseClrB_R;
    /* 0x0A */ uint8_t diffuseClrB_G;
    /* 0x0B */ uint8_t diffuseClrB_B;
    /* 0x0C */ uint8_t diffuseDirB_X;
    /* 0x0D */ uint8_t diffuseDirB_Y;
    /* 0x0E */ uint8_t diffuseDirB_Z;
    /* 0x0F */ uint8_t fogClrR;
    /* 0x10 */ uint8_t fogClrG;
    /* 0x11 */ uint8_t fogClrB;
    /* 0x12 */ uint16_t fogNear;
    /* 0x14 */ uint16_t drawDistance;
} LightSettings; /* 0x16 */

typedef struct {
    /* 0x00 */ int16_t ambientColor[3];
    /* 0x06 */ int16_t diffuseColor1[3];
    /* 0x0C */ int16_t diffuseColor2[3];
    /* 0x12 */ int16_t fogColor[3];
    /* 0x18 */ int16_t fogNear;
    /* 0x1A */ int16_t fogFar;
} LightSettings2; /* sizeof = 0x1C */

#endif
