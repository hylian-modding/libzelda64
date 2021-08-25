#ifndef FONT_TYPE_H
#define FONT_TYPE_H

#include <inttypes.h>

#define FONT_CHAR_TEX_SIZE 128 // 16x16 I4 texture

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0

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

#else /* GAME_VERSION_1_0 */
#warning "Font is not defined for this game version!"

#endif
#elif defined GAME_MM /* GAME_OOT */
// Font textures are loaded into here
typedef struct {
    /* 0x00000 */ uint8_t charBuf[2][FONT_CHAR_TEX_SIZE * 120];
    /* 0x07800 */ uint8_t iconBuf[FONT_CHAR_TEX_SIZE];
    /* 0x07880 */ uint8_t fontBuf[FONT_CHAR_TEX_SIZE * 320];
    /* 0x11880 */ union {
        uint8_t schar[640];
        uint16_t wchar[640];
    } msgBuf;
    /* 0x11D80 */ uint8_t* messageStart;
    /* 0x11D84 */ uint8_t* messageEnd;
    /* 0x11D88 */ uint8_t unk_11D88;
} Font; /* size = 0x11D8C */

#endif
#endif
