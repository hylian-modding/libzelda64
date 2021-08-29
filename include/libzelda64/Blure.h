#ifndef BLURE_FUNC_H
#define BLURE_FUNC_H

#include "types/EffectBlure.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void Effect_Add(struct GlobalContext* globalCtx, int32_t* pIndex, int32_t type, uint8_t arg3, uint8_t arg4, void* initParams);
SYMBOL_VERSION_CONFIG(Effect_Add, 0x8001AA5C, 0x800AF960);

extern void EffectBlure_AddVertex(EffectBlure* this, struct Vec3f* p1, struct Vec3f* p2);
SYMBOL_VERSION_CONFIG(EffectBlure_AddVertex, 0x80013F30, 0x80000180);

extern void* Effect_GetByIndex(int32_t index);
SYMBOL_VERSION_CONFIG(Effect_GetByIndex, 0x8001A890, 0x80000180);

#endif