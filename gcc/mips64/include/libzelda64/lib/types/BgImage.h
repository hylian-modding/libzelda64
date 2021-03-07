#ifndef BGIMAGE_TYPE_H
#define BGIMAGE_TYPE_H

#include <inttypes.h>

typedef struct BgImage {
    /* 0x00 */ uint16_t unk_00;
    /* 0x02 */ uint8_t id;
    /* 0x04 */ uint32_t source;
    /* 0x08 */ uint32_t unk_0C;
    /* 0x0C */ uint32_t tlut;
    /* 0x10 */ uint16_t width;
    /* 0x12 */ uint16_t height;
    /* 0x14 */ uint8_t fmt;
    /* 0x15 */ uint8_t siz;
    /* 0x16 */ uint16_t mode0;
    /* 0x18 */ uint16_t tlutCount;
} BgImage; /* sizeof = 0x1C */

#endif

