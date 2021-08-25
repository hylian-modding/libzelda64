#ifndef PLAYERAGEPROPERTIES_TYPE_H
#define PLAYERAGEPROPERTIES_TYPE_H

#include "Vec3s.h"
#include <inttypes.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct PlayerAgeProperties {
    /* 0x00 */ float unk_00;
    /* 0x04 */ float unk_04;
    /* 0x08 */ float unk_08;
    /* 0x0C */ float unk_0C;
    /* 0x10 */ float unk_10;
    /* 0x14 */ float unk_14;
    /* 0x18 */ float unk_18;
    /* 0x1C */ float unk_1C;
    /* 0x20 */ float unk_20;
    /* 0x24 */ float unk_24;
    /* 0x28 */ float unk_28;
    /* 0x2C */ float unk_2C;
    /* 0x30 */ float unk_30;
    /* 0x34 */ float unk_34;
    /* 0x38 */ float unk_38;
    /* 0x3C */ float unk_3C;
    /* 0x40 */ float unk_40;
    /* 0x44 */ Vec3s unk_44;
    /* 0x4A */ Vec3s unk_4A[4];
    /* 0x62 */ Vec3s unk_62[4];
    /* 0x7A */ Vec3s unk_7A[2];
    /* 0x86 */ Vec3s unk_86[2];
    /* 0x92 */ uint16_t unk_92;
    /* 0x94 */ uint16_t unk_94;
    /* 0x98 */ struct LinkAnimationHeader* unk_98;
    /* 0x9C */ struct LinkAnimationHeader* unk_9C;
    /* 0xA0 */ struct LinkAnimationHeader* unk_A0;
    /* 0xA4 */ struct LinkAnimationHeader* unk_A4;
    /* 0xA8 */ struct LinkAnimationHeader* unk_A8;
    /* 0xAC */ struct LinkAnimationHeader* unk_AC[4];
    /* 0xBC */ struct LinkAnimationHeader* unk_BC[2];
    /* 0xC4 */ struct LinkAnimationHeader* unk_C4[2];
    /* 0xCC */ struct LinkAnimationHeader* unk_CC[2];
} PlayerAgeProperties; /* size = 0xD4 */
#else                  /* GAME_VERSION_1_0 */
#warning "Actor is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct PlayerAgeProperties {
    /* 0x00 */ float unk_00;
    /* 0x04 */ float unk_04;
    /* 0x08 */ float unk_08;
    /* 0x0C */ float unk_0C;
    /* 0x10 */ float unk_10;
    /* 0x14 */ float unk_14;
    /* 0x18 */ float unk_18;
    /* 0x1C */ float unk_1C;
    /* 0x20 */ float unk_20;
    /* 0x24 */ float unk_24;
    /* 0x28 */ float unk_28;
    /* 0x2C */ float unk_2C;
    /* 0x30 */ float unk_30;
    /* 0x34 */ float unk_34;
    /* 0x38 */ float unk_38;
    /* 0x3C */ float unk_3C;
    /* 0x40 */ float unk_40;
    /* 0x44 */ Vec3s unk_44;
    /* 0x4A */ Vec3s unk_4A[4];
    /* 0x62 */ Vec3s unk_62[4];
    /* 0x7A */ Vec3s unk_7A[4];
    /* 0x92 */ uint16_t unk_92;
    /* 0x94 */ uint16_t unk_94;
    /* 0x98 */ float unk_98;
    /* 0x9C */ float unk_9C;
    /* 0xA0 */ struct LinkAnimationHeader* unk_A0;
    /* 0xA4 */ struct LinkAnimationHeader* unk_A4;
    /* 0xA8 */ struct LinkAnimationHeader* unk_A8;
    /* 0xAC */ struct LinkAnimationHeader* unk_AC;
    /* 0xB0 */ struct LinkAnimationHeader* unk_B0;
    /* 0xB4 */ struct LinkAnimationHeader* unk_B4[4];
    /* 0xC4 */ struct LinkAnimationHeader* unk_C4[2];
    /* 0xCC */ struct LinkAnimationHeader* unk_CC[2];
    /* 0xD4 */ struct LinkAnimationHeader* unk_D4[2];
} PlayerAgeProperties; /* sizeof = 0xDC */
#endif                /* GAME_MM */

#endif
