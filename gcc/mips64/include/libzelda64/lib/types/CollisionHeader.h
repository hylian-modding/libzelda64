#ifndef COLLISIONHEADER_TYPE_H
#define COLLISIONHEADER_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct CollisionHeader {
    /* 0x00 */ Vec3s minBounds;
    /* 0x06 */ Vec3s maxBounds;
    /* 0x0C */ uint16_t nbVertices;
    /* 0x10 */ struct Vec3s* vtxList;
    /* 0x14 */ uint16_t nbPolygons;
    /* 0x18 */ struct CollisionPoly* polyList;
    /* 0x1C */ struct SurfaceType* surfaceTypeList;
    /* 0x20 */ struct CamData* cameraDataList;
    /* 0x24 */ uint16_t nbWaterBoxes;
    /* 0x28 */ struct WaterBox* waterBoxes;
} CollisionHeader; /* sizeof = 0x2C */

#endif

