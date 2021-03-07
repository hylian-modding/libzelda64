#ifndef CAMDATA_TYPE_H
#define CAMDATA_TYPE_H

#include <inttypes.h>

typedef struct CamData {
    /* 0x00 */ uint16_t cameraSType;
    /* 0x02 */ int16_t numCameras;
    /* 0x04 */ struct Vec3s* camPosData;
} CamData; /* sizeof = 0x-8 */

#endif

