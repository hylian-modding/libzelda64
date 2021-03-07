#ifndef ROOM_TYPE_H
#define ROOM_TYPE_H

#include <inttypes.h>

typedef struct Room {
    /* 0x00 */ int8_t num;
    /* 0x01 */ int8_t area;
    /* 0x02 */ uint8_t weather;
    /* 0x03 */ uint8_t type;
    /* 0x04 */ uint8_t echo;
    /* 0x05 */ uint8_t showInvisActors;
    /* 0x08 */ struct Mesh* mesh;
    /* 0x0C */ void* segment;
    /* 0x10 */ int toolOffset;
} Room; /* sizeof = 0x14 */


#endif

