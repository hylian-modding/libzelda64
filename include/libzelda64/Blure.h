#ifndef BLURE_FUNC_H
#define BLURE_FUNC_H

#include "types/EffectBlure.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void Effect_Add(struct GlobalContext* globalCtx, int32_t* pIndex, int32_t type, uint8_t arg3, uint8_t arg4, void* initParams);
SYMBOL_VERSION_CONFIG(Effect_Add, 0x8001AA5C, 0x800AF960);

extern void EffectBlure_AddVertex(EffectBlure* this, Vec3f* p1, Vec3f* p2);
SYMBOL_VERSION_CONFIG(EffectBlure_AddVertex, 0x80013F30, 0x800A81F0);

extern void EffectBlure_AddSpace(EffectBlure* this);
SYMBOL_VERSION_CONFIG(EffectBlure_AddSpace, 0x80014254, 0x800A8514);

extern void EffectBlure_InitElements(EffectBlure* this);
SYMBOL_VERSION_CONFIG(EffectBlure_InitElements, 0x80014298, 0x800A8558);

extern void EffectBlure_Init1(void* thisx, void* initParamsx);
SYMBOL_VERSION_CONFIG(EffectBlure_Init1, 0x80014350, 0x800A8610);

extern void EffectBlure_Init2(void* thisx, void* initParamsx);
SYMBOL_VERSION_CONFIG(EffectBlure_Init2, 0x80014460, 0x800A8720);

extern void EffectBlure_Destroy(void* thisx);
SYMBOL_VERSION_CONFIG(EffectBlure_Destroy, 0x80014594, 0x800A8854);

extern int32_t EffectBlure_Update(void* thisx);
SYMBOL_VERSION_CONFIG(EffectBlure_Update, 0x800145A0, 0x800A8860);

extern void EffectBlure_UpdateFlags(EffectBlureElement* elem);
SYMBOL_VERSION_CONFIG(EffectBlure_UpdateFlags, 0x80014A04, 0x800A8C78);

extern void EffectBlure_GetComputedValues(EffectBlure* this, int32_t index, float ratio, Vec3s* vec1, Vec3s* vec2, Color_RGBA8* color1, Color_RGBA8* color2);
SYMBOL_VERSION_CONFIG(EffectBlure_GetComputedValues, 0x80014B74, 0x800A8DE8);

extern void EffectBlure_SetupSmooth(EffectBlure* this, GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(EffectBlure_SetupSmooth, 0x80015088, 0x800A92FC);

extern void EffectBlure_DrawElemNoInterpolation(EffectBlure* this, EffectBlureElement* elem, int32_t index, GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(EffectBlure_DrawElemNoInterpolation, 0x800150BC, 0x800A9330);

extern void EffectBlure_DrawElemHermiteInterpolation(EffectBlure* this, EffectBlureElement* elem, int32_t index, GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(EffectBlure_DrawElemHermiteInterpolation, 0x80015590, 0x800A9804);

extern void EffectBlure_DrawSmooth(EffectBlure* this2, GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(EffectBlure_DrawSmooth, 0x80015F64, 0x800AA190);

extern void EffectBlure_SetupSimple(GraphicsContext* gfxCtx, EffectBlure* this, Vtx* vtx);
SYMBOL_VERSION_CONFIG(EffectBlure_SetupSimple, 0x80016234, 0x800AA460);

extern void EffectBlure_SetupSimpleAlt(GraphicsContext* gfxCtx, EffectBlure* this, Vtx* vtx);
SYMBOL_VERSION_CONFIG(EffectBlure_SetupSimpleAlt, 0x8001626C, 0x800AA498);

extern void EffectBlure_DrawSimpleVertices(GraphicsContext* gfxCtx, EffectBlure* this, Vtx* vtx);
SYMBOL_VERSION_CONFIG(EffectBlure_DrawSimpleVertices, 0x800164C8, 0x800AA700);

extern void EffectBlure_DrawSimple(EffectBlure* this2, GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(EffectBlure_DrawSimple, 0x800169B4, 0x800AABE0);

extern void EffectBlure_Draw(void* thisx, GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(EffectBlure_Draw, 0x80016EC0, 0x800AB0EC);

#endif