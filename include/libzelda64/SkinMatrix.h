#ifndef SKINMATRIX_FUNC_H
#define SKINMATRIX_FUNC_H

#include "types/MtxF.h"
#include "zelda64_version.h"
#include <inttypes.h>
#include <PR/gbi.h>

extern void SkinMatrix_SetTranslate(MtxF* mf, float x, float y, float z);
SYMBOL_VERSION_CONFIG(SkinMatrix_SetTranslate, 0x8008F82C, 0x801397ac);

extern void SkinMatrix_SetScale(MtxF* mf, float x, float y, float z);
SYMBOL_VERSION_CONFIG(SkinMatrix_SetScale, 0x8008F4A8, 0x80139428);

extern void SkinMatrix_MtxFMtxFMult(MtxF* mfB, MtxF* mfA, MtxF* dest);
SYMBOL_VERSION_CONFIG(SkinMatrix_MtxFMtxFMult, 0x8008EDB8, 0x80138d38);

extern Mtx* SkinMatrix_MtxFToNewMtx(struct GraphicsContext* gfxCtx, MtxF* src);
SYMBOL_VERSION_CONFIG(SkinMatrix_MtxFToNewMtx, 0x8008FC98, 0x80139c18);

#endif