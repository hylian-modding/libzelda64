#ifndef MESH_TYPE_H
#define MESH_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

typedef struct Polygon {
    /* 0x00 */ uint8_t type;
    /* 0x01 */ uint8_t num; // number of dlist entries
    /* 0x04 */ void* start;
    /* 0x08 */ void* end;
} Polygon, PolygonType0; /* sizeof = 0x0C */

typedef struct PolygonType1 {
    /* 0x00 */ uint8_t type;
    /* 0x01 */ uint8_t format; // 1 = single, 2 = multi
    /* 0x04 */ void* dlist;
    union {
        struct {
            /* 0x08 */ uint32_t source;
            /* 0x0C */ uint32_t unk_0C;
            /* 0x10 */ uint32_t tlut;
            /* 0x14 */ uint16_t width;
            /* 0x16 */ uint16_t height;
            /* 0x18 */ uint8_t fmt;
            /* 0x19 */ uint8_t siz;
            /* 0x1A */ uint16_t mode0;
            /* 0x1C */ uint16_t tlutCount;
        } single;
        struct {
            /* 0x08 */ uint8_t count;
            /* 0x0C */ struct BgImage* list;
        } multi;
    };
} PolygonType1; /* sizeof = 0x1E */

typedef struct PolygonType2 {
    /* 0x00 */ uint8_t type;
    /* 0x01 */ uint8_t num; // number of dlist entries
    /* 0x04 */ void* start;
    /* 0x08 */ void* end;
} PolygonType2; /* sizeof = 0x0C */

typedef union Mesh {
    /* 0x00 */ Polygon polygon;
    /* 0x00 */ PolygonType0 polygon0;
    /* 0x00 */ PolygonType1 polygon1;
    /* 0x00 */ PolygonType2 polygon2;
} Mesh, RoomMesh; /* sizeof = 0x1C */


#endif
