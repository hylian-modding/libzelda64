#ifndef DYNAPOLYACTOR_TYPE_H
#define DYNAPOLYACTOR_TYPE_H

#include "Actor.h"
#include <inttypes.h>

typedef enum {
    DPM_UNK = 0,
    DPM_PLAYER = 1,
    DPM_ENEMY = 2,
    DPM_UNK3 = 3
} DynaPolyMoveFlag;

typedef struct DynaPolyActor {
    /* 0x000 */ Actor actor;
    /* 0x13C */ int32_t bgId;
    /* 0x140 */ float unk_140;
    /* 0x144 */ float unk_144;
    /* 0x148 */ int16_t unk_148; // y rotation?
    /* 0x14A */ uint16_t unk_14A;
    /* 0x14C */ uint32_t unk_14C;
    /* 0x150 */ uint8_t unk_150;
    /* 0x152 */ int16_t unk_152;
} DynaPolyActor; /* sizeof = 0x154 */

#endif

