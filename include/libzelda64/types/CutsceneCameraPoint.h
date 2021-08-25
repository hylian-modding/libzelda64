#ifndef CUTSCENECAMERAPOINT_TYPE_H
#define CUTSCENECAMERAPOINT_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct CutsceneCameraPoint {
    /* 0x00 */ int8_t continueFlag;
    /* 0x01 */ int8_t cameraRoll;
    /* 0x02 */ uint16_t nextPointFrame;
    /* 0x04 */ float viewAngle; // in degrees
    /* 0x08 */ Vec3s pos;
} CutsceneCameraPoint; /* sizeof = 0x10 */

#endif
