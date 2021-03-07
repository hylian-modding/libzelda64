#ifndef SKYBOXCONTEXT_TYPE_H
#define SKYBIXCONTEXT_TYPE_H

#include "View.h"
#include "Vec3f.h"
#include <inttypes.h>
#include <libultra/PR/gbi.h>

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

#endif

