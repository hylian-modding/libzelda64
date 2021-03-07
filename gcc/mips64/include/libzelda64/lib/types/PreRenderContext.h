#ifndef PRERENDERCONTEXT_TYPE_H
#define PRERENDERCONTEXT_TYPE_H

#include "ListAlloc.h"
#include <inttypes.h>

typedef struct PreRenderContext {
    /* 0x00 */ int32_t width;
    /* 0x04 */ int32_t height;
    /* 0x08 */ int32_t widthSave;
    /* 0x0C */ int32_t heightSave;
    /* 0x10 */ uint16_t* fbuf;
    /* 0x14 */ uint16_t* fbufSave;
    /* 0x18 */ uint8_t* cvgSave;
    /* 0x1C */ uint16_t* zbuf;
    /* 0x20 */ uint16_t* zbufSave;
    /* 0x24 */ int32_t ulxSave;
    /* 0x28 */ int32_t ulySave;
    /* 0x2C */ int32_t lrxSave;
    /* 0x30 */ int32_t lrySave;
    /* 0x34 */ int32_t ulx;
    /* 0x38 */ int32_t uly;
    /* 0x3C */ int32_t lrx;
    /* 0x40 */ int32_t lry;
    /* 0x44 */ ListAlloc alloc;
    /* 0x4C */ uint32_t isAllocMyself;
} PreRenderContext; // size = 0x50

#endif

