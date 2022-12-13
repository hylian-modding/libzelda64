#ifndef SRAMCONTEXT_TYPE_H
#define SRAMCONTEXT_TYPE_H

#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct SramContext {
    /* 0x00 */ uint8_t* readBuff;
} SramContext; /* sizeof = 0x04 */

#else /* GAME_VERSION_1_0 */
#warning "SramContext is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct SramContext {
    /* 0x00 */ uint8_t* readBuff;
    /* 0x04 */ uint32_t* flashReadBuff;
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ int16_t status;
    /* 0x10 */ uint32_t curPage;
    /* 0x14 */ uint32_t numPages;
    /* 0x18 */ OSTime unk_18;
    /* 0x20 */ int16_t unk_20;
    /* 0x22 */ int16_t unk_22;
    /* 0x24 */ int16_t unk_24;
} SramContext; /* sizeof = 0x28 */
#endif

#endif
