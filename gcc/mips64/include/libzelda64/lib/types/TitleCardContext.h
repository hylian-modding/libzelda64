#ifndef TITLECARDCONTEXT_TYPE_H
#define TITLECARDCONTEXT_TYPE_H

#include <inttypes.h>

typedef struct {
    /* 0x00 */ uint8_t* texture;
    /* 0x04 */ int16_t x;
    /* 0x06 */ int16_t y;
    /* 0x08 */ uint8_t w;
    /* 0x09 */ uint8_t h;
    /* 0x0A */ uint8_t delayA;
    /* 0x0B */ uint8_t delayB;
    /* 0x0C */ int16_t alpha;
    /* 0x0E */ int16_t color;
} TitleCardContext; /* 0x10 */

#endif

