#ifndef SKELANIME_FUNC_H
#define SKELANIME_FUNC_H

#include "types/AnimationHeader.h"
#include "types/AnimationHeaderCommon.h"
#include "types/FlexSkeletonHeader.h"
#include "types/SkelAnime.h"
#include "types/SkeletonHeader.h"
#include "types/Vec3s.h"
#include "zelda64_version.h"
#include <inttypes.h>

// SkelAnime_DrawFlexOpa_LimbCallback (always return 0?)
typedef int32_t (*OverrideLimbDrawOpa)(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3f* pos, Vec3s* rot, void* actor);
// SkelAnime_DrawFlexOpa_SegTextureCallback (always return 1?)
typedef void (*PostLimbDrawOpa)(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3s* rot, void* actor);

extern int32_t SkelAnime_Init(
    struct GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg, struct AnimationHeader* animation, Vec3s* limbDrawTable, Vec3s* morfDrawTable, int32_t limbCount);
SYMBOL_VERSION_CONFIG(SkelAnime_Init, 0x8008C684, 0x80136A7C);

extern int32_t SkelAnime_InitFlex(
    struct GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg, struct AnimationHeader* animation, Vec3s* limbDrawTable, Vec3s* limbPosTable, int32_t limbCount);
SYMBOL_VERSION_CONFIG(SkelAnime_InitFlex, 0x8008C788, 0x801385A0);

// SkelAnime_InitLinkAnimation / Skeleton_Info_Rom_SV_ct on Poe's sheet (Decomp renamed, ovl didn't have)
extern void SkelAnime_InitLink(
    struct GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg, struct LinkAnimationHeader* animation, int32_t initFlags, struct Vec3s* jointTable,
    struct Vec3s* morphTable, int32_t limbCount);
SYMBOL_VERSION_CONFIG(SkelAnime_InitLink, 0x8008BB08, 0x80135F88);

extern void SkelAnime_ChangeAnim(SkelAnime* skelAnime, struct AnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames);
SYMBOL_VERSION_CONFIG(SkelAnime_ChangeAnim, 0x8008D17C, 0x801373E8);

extern void SkelAnime_DrawOpa(struct GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* instance);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawOpa, 0x8008993C, 0x80133B3C);

extern void SkelAnime_DrawFlexOpa(
    struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, int32_t dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* instance);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexOpa, 0x80089D8C, 0x80135998);

extern void SkelAnime_DrawFlexLod(
    struct GlobalContext* globalCtx, void** skeleton, struct Vec3s* jointTable, int32_t dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t dListIndex);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLod, 0x800894A4, 0x80134DBC);

extern int16_t Animation_GetLength(void* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLength, 0x8008A158, 0x80134748);

#endif
