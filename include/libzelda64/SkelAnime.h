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

typedef int32_t (*OverrideLimbDraw)(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, struct Vec3f* pos, Vec3s* rot, void* actor, struct Gfx** gfx);

typedef void (*PostLimbDraw)(struct GlobalContext* globalCtx, int32_t limbIndex, struct Gfx** dList, Vec3s* rot, void* actor, struct Gfx** gfx);

extern void SkelAnime_DrawLimbLod(GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t lod);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawLimbLod, 0x80088DF0, 0x801330E0);

extern void SkelAnime_DrawLod(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t lod);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawLod, 0x8008902C, 0x801332F0);

extern void SkelAnime_DrawFlexLimbLod(GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t lod, Mtx** mtx);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLimbLod, 0x8008921C, 0x801334A0);

extern void SkelAnime_DrawFlexLod(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, int32_t dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t lod);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLod, 0x800894A4, 0x80133710);

extern void SkelAnime_DrawLimbOpa(GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawLimbOpa, 0x8008971C, 0x80133948);

extern void SkelAnime_DrawOpa(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawOpa, 0x8008993C, 0x80133B3C);

extern void SkelAnime_DrawFlexLimbOpa(GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, Mtx** limbMatricies);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLimbOpa, 0x80089B1C, 0x80133CDC);

extern void SkelAnime_DrawFlexOpa(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, int32_t dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexOpa, 0x80089D8C, 0x80133F28);

//extern ? func_80134148();
//SYMBOL_VERSION_CONFIG(func_80134148, 0x80000180, 0x80134148);

//extern ? func_801343C0();
//SYMBOL_VERSION_CONFIG(func_801343C0, 0x80000180, 0x801343C0);

extern void SkelAnime_GetFrameData(AnimationHeader* animation, int32_t frame, int32_t limbCount, Vec3s* frameTable);
SYMBOL_VERSION_CONFIG(SkelAnime_GetFrameData, 0x80089FF0, 0x80134600);

extern int16_t Animation_GetLength(void* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLength, 0x8008A158, 0x80134724);

extern int16_t Animation_GetLastFrame(void* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLastFrame, 0x8008A194, 0x80134748);

extern Gfx* SkelAnime_DrawLimb(GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawLimb, 0x8008A1DC, 0x80134774);

extern Gfx* SkelAnime_Draw(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
SYMBOL_VERSION_CONFIG(SkelAnime_Draw, 0x8008A414, 0x80134990);

extern Gfx* SkelAnime_DrawFlexLimb(GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Mtx** mtx, Gfx* gfx);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLimb, 0x8008A608, 0x80134B54);

extern Gfx* SkelAnime_DrawFlex(GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, int32_t dListCount, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlex, 0x8008A88C, 0x80134DBC);

extern int32_t SkelAnime_GetFrameDataLegacy(struct LegacyAnimationHeader* animation, int32_t frame, Vec3s* frameTable);
SYMBOL_VERSION_CONFIG(SkelAnime_GetFrameDataLegacy, 0x8008AAF4, 0x80134FFC);

extern int16_t Animation_GetLimbCountLegacy(struct LegacyAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLimbCountLegacy, 0x8008AEF8, 0x801353D4);

extern int16_t Animation_GetLengthLegacy(struct LegacyAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLengthLegacy, 0x8008AF34, 0x801353F8);

extern int16_t Animation_GetLastFrameLegacy(struct LegacyAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLastFrameLegacy, 0x8008AF70, 0x8013541C);

extern void SkelAnime_InterpFrameTable(s32 limbCount, Vec3s* dst, Vec3s* start, Vec3s* target, float weight);
SYMBOL_VERSION_CONFIG(SkelAnime_InterpFrameTable, 0x8008AFB8, 0x80135448);

extern int32_t SkelAnime_Init(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg, AnimationHeader* animation, Vec3s* jointTable, Vec3s* morphTable, int32_t limbCount);
SYMBOL_VERSION_CONFIG(SkelAnime_Init, 0x8008C684, 0x80136A7C);

extern int32_t SkelAnime_InitFlex(GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg, AnimationHeader* animation, Vec3s* jointTable, Vec3s* morphTable, int32_t limbCount);
SYMBOL_VERSION_CONFIG(SkelAnime_InitFlex, 0x8008C788, 0x80136B30);

extern int32_t SkelAnime_InitSkin(GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg, AnimationHeader* animation);
SYMBOL_VERSION_CONFIG(SkelAnime_InitSkin, 0x8008C894, 0x80136BEC);

extern void SkelAnime_SetUpdate(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_SetUpdate, 0x8008C974, 0x80136C84);

extern int32_t SkelAnime_Update(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_Update, 0x8008C9C0, 0x80136CD0);

extern int32_t SkelAnime_Morph(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_Morph, 0x8008C9E4, 0x80136CF4);

extern int32_t SkelAnime_MorphTaper(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_MorphTaper, 0x8008CAA4, 0x80136D98);

extern void SkelAnime_AnimateFrame(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_AnimateFrame, 0x8008CC2C, 0x80136F04);

extern int32_t SkelAnime_LoopFull(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_LoopFull, 0x8008CD74, 0x8013702C);

extern int32_t SkelAnime_LoopPartial(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_LoopPartial, 0x8008CE14, 0x801370B0);

extern int32_t SkelAnime_Once(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_Once, 0x8008CEBC, 0x8013713C);

extern void Animation_ChangeImpl(SkelAnime* skelAnime, AnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames, int8_t taper);
SYMBOL_VERSION_CONFIG(Animation_ChangeImpl, 0x8008CFC0, 0x8013722C);

extern void Animation_Change(SkelAnime* skelAnime, AnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames);
SYMBOL_VERSION_CONFIG(Animation_Change, 0x8008D17C, 0x801373E8);

extern void Animation_PlayOnce(SkelAnime* skelAnime, AnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_PlayOnce, 0x8008D1C4, 0x80137430);

extern void Animation_MorphToPlayOnce(SkelAnime* skelAnime, AnimationHeader* animation, float morphFrames);
SYMBOL_VERSION_CONFIG(Animation_MorphToPlayOnce, 0x8008D21C, 0x80137488);

extern void Animation_PlayOnceSetSpeed(SkelAnime* skelAnime, AnimationHeader* animation, float playSpeed);
SYMBOL_VERSION_CONFIG(Animation_PlayOnceSetSpeed, 0x8008D278, 0x801374E4);

extern void Animation_PlayLoop(SkelAnime* skelAnime, AnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_PlayLoop, 0x8008D2D4, 0x80137540);

extern void Animation_MorphToLoop(SkelAnime* skelAnime, AnimationHeader* animation, float morphFrames);
SYMBOL_VERSION_CONFIG(Animation_MorphToLoop, 0x8008D328, 0x80137594);

extern void Animation_PlayLoopSetSpeed(SkelAnime* skelAnime, AnimationHeader* animation, float playSpeed);
SYMBOL_VERSION_CONFIG(Animation_PlayLoopSetSpeed, 0x8008D360, 0x801375CC);

extern void Animation_EndLoop(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(Animation_EndLoop, 0x8008D3B8, 0x80137624);

extern void Animation_Reverse(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(Animation_Reverse, 0x8008D3E4, 0x80137650);

extern void SkelAnime_CopyFrameTableTrue(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(SkelAnime_CopyFrameTableTrue, 0x8008D408, 0x80137674);

extern void SkelAnime_CopyFrameTableFalse(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(SkelAnime_CopyFrameTableFalse, 0x8008D470, 0x801376DC);

extern void SkelAnime_UpdateTranslation(SkelAnime* skelAnime, Vec3f* diff, int16_t angle);
SYMBOL_VERSION_CONFIG(SkelAnime_UpdateTranslation, 0x8008D4DC, 0x80137748);

extern int32_t Animation_OnFrame(SkelAnime* skelAnime, float frame);
SYMBOL_VERSION_CONFIG(Animation_OnFrame, 0x8008D6A8, 0x801378B8);

extern void SkelAnime_Free(SkelAnime* skelAnime, GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(SkelAnime_Free, 0x8008D6D0, 0x801378E0);

extern void SkelAnime_CopyFrameTable(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src);
SYMBOL_VERSION_CONFIG(SkelAnime_CopyFrameTable, 0x8008D71C, 0x8013792C);

#endif
