#ifndef PRERENDERCONTEXT_TYPE_H
#define PRERENDERCONTEXT_TYPE_H

#include "ListAlloc.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
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
} PreRenderContext; /* sizeof = 0x50 */

#else /* GAME_VERSION_1_0 */
#warning "GlobalContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x00 */ uint16_t width; // is MM decomp wrong about these? am I?
    /* 0x02 */ uint16_t height;
    /* 0x04 */ uint16_t widthSave;
    /* 0x06 */ uint16_t heightSave;
    /* 0x08 */ char unk_8[8];
    /* 0x10 */ uint16_t* fbuf;
    /* 0x14 */ uint16_t* fbufSave;
    /* 0x18 */ uint8_t* cvgSave;
    /* 0x1C */ uint16_t* zbuf;
    /* 0x20 */ uint16_t* zbufSave;
    /* 0x24 */ uint16_t ulxSave;
    /* 0x26 */ uint16_t ulySave;
    /* 0x28 */ uint16_t lrxSave;
    /* 0x2A */ uint16_t lrySave;
    /* 0x2C */ uint16_t ulx;
    /* 0x2E */ uint16_t uly;
    /* 0x30 */ uint16_t lrx;
    /* 0x32 */ uint16_t lry;
    /* 0x34 */ char unk_34[16];
    /* 0x44 */ ListAlloc alloc;
    /* 0x4C */ uint8_t unk_4C;
    /* 0x4D */ uint8_t unk_4D;
    /* 0x4E */ char unk_4E[2];
} PreRenderContext; /* size = 0x50 */
#endif                /* GAME_MM */

#endif
