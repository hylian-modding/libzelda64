#ifndef SKYBOXCONTEXT_TYPE_H
#define SKYBOXCONTEXT_TYPE_H

#include "DmaRequest.h"
#include "Vec3f.h"
#include "View.h"
#include <inttypes.h>
#include <ultra64.h>

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct SkyboxContext {
    /* 0x000 */ View view;
    /* 0x128 */ void* staticSegments[3];
    /* 0x134 */ struct Gfx* dpList;
    /* 0x138 */ struct Gfx* roomDL;
    /* 0x13C */ Vtx_t* roomVtx;
    /* 0x140 */ int16_t drawFlag;
    /* 0x144 */ Vec3f rot;
    /* 0x150 */ Vec3f eye;
    /* 0x15C */ int16_t angle;
    /* 0x15E */ int16_t _pad;
} SkyboxContext; /* sizeof  0x160 */

#else
#warning "SkyboxContext is not defined for this game version!"
#endif
#elif defined GAME_MM
typedef struct SkyboxContext {
    /* 0x000 */ View view;
    /* 0x168 */ void* staticSegments[2];
    /* 0x170 */ char unk170[8]; // more static segments?
    /* 0x178 */ void* skyboxPaletteStaticSegment;
    /* 0x17C */ struct Gfx* unk17C;
    /* 0x180 */ struct Gfx* unk180;
    /* 0x184 */ Vtx* roomVtx;
    /* 0x188 */ DmaRequest unk188;
    /* 0x1A8 */ DmaRequest unk1A8;
    /* 0x1C8 */ DmaRequest unk1C8;
    /* 0x1E8 */ OSMesgQueue loadQueue;
    /* 0x200 */ OSMesg loadMsg;
    /* 0x204 */ int16_t skyboxShouldDraw;
    /* 0x208 */ Vec3f rot;
    /* 0x214 */ Vec3f eye;
    /* 0x220 */ int16_t angle;
    /* 0x222 */ uint8_t primR;
    /* 0x223 */ uint8_t primG;
    /* 0x224 */ uint8_t primB;
    /* 0x225 */ uint8_t envR;
    /* 0x226 */ uint8_t envG;
    /* 0x227 */ uint8_t envB;
} SkyboxContext; /* sizeof = 0x228 */
#endif

#endif
