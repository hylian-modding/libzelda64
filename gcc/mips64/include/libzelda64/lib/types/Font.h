#ifndef FONT_TYPE_H
#define FONT_TYPE_H

#include <inttypes.h>

#define FONT_CHAR_TEX_SIZE 128 // 16x16 I4 texture

typedef struct Font {
    /* 0x0000 */ uint32_t msgOffset;
    /* 0x0004 */ uint32_t msgLength;
    /* 0x0008 */ uint8_t fontBuffer[0x3C00];
    /* 0x3C08 */ uint8_t iconBuf[FONT_CHAR_TEX_SIZE];
    /* 0x3C88 */ uint8_t fontBuf[FONT_CHAR_TEX_SIZE * 320];
    union {
        union {
            /* 0xDC88 */ uint16_t msgBuf[16 * 40];
            /* 0xDC88 */ uint8_t nesMsgBuf[16 * 40];
        } localized;
        /* 0xDC88 */ uint8_t msgBuf[1064]; // decomp's size is wrong kekw
    };
} Font; /* sizeof = 0xE188 */

#endif

