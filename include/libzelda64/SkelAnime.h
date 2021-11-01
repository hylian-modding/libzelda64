#ifndef SKELANIME_FUNC_H
#define SKELANIME_FUNC_H

#include "types/AnimationHeader.h"
#include "types/AnimationEntry.h"
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

extern void SkelAnime_DrawLimbLod(struct GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t lod);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawLimbLod, 0x80088DF0, 0x80134B50);

extern void SkelAnime_DrawLod(struct GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t dListIndex);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawLod, 0x8008902C, 0x80134D60);

extern void SkelAnime_DrawFlexLimbLod(struct GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t lod, Mtx** mtx);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLimbLod, 0x8008921C, 0x80134F10);

extern void SkelAnime_DrawFlexLod(struct GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, int32_t dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t dListIndex);
//SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLod, 0x800894A4, 0x80134DBC);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLod, 0x800894A4, 0x80135180);

extern void SkelAnime_DrawLimbOpa(struct GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawLimbOpa, 0x8008971C, 0x801353B8);

extern void SkelAnime_DrawOpa(struct GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
//SYMBOL_VERSION_CONFIG(SkelAnime_DrawOpa, 0x8008993C, 0x80133B3C);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawOpa, 0x8008993C, 0x801355AC);

extern void SkelAnime_DrawFlexLimbOpa(struct GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, Mtx** limbMatricies);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLimbOpa, 0x80089B1C, 0x8013574C);

extern void SkelAnime_DrawFlexOpa(struct GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, int32_t dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg);
//SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexOpa, 0x80089D8C, 0x80133F28);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexOpa, 0x80089D8C, 0x80135998);

//extern void SkelAnime_DrawFlexLimbOpaSC();
//SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLimbOpaSC, 0x80000180, 0x80135BB8);

//extern void SkelAnime_DrawFlexOpaSC();
//SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexOpaSC, 0x80000180, 0x80135E30);

extern int32_t SkelAnime_GetFrameData(struct LegacyAnimationHeader* animation, int32_t frame, Vec3s* frameTable);
SYMBOL_VERSION_CONFIG(SkelAnime_GetFrameData, 0x80089FF0, 0x80136070);

extern int16_t Animation_GetLength(void* animation);
//SYMBOL_VERSION_CONFIG(Animation_GetLength, 0x8008A158, 0x80134748);
SYMBOL_VERSION_CONFIG(Animation_GetLength, 0x8008A158, 0x80136194);

extern int16_t Animation_GetLastFrame(void* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLastFrame, 0x8008A194, 0x801361B8);

extern Gfx* SkelAnime_DrawLimb(struct GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, struct Gfx* gfx);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawLimb, 0x8008A1DC, 0x801361E4);

extern void SkelAnime_Draw(struct GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t dListIndex);
SYMBOL_VERSION_CONFIG(SkelAnime_Draw, 0x8008A414, 0x80136400);

extern Gfx* SkelAnime_DrawFlexLimb(struct GlobalContext* globalCtx, int32_t limbIndex, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, struct Mtx** mtx, struct Gfx* gfx);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlexLimb, 0x8008A608, 0x801365C4);

extern void SkelAnime_DrawFlex(struct GlobalContext* globalCtx, void** skeleton, Vec3s* jointTable, int32_t dListCount, OverrideLimbDrawOpa overrideLimbDraw, PostLimbDrawOpa postLimbDraw, void* arg, int32_t dListIndex);
SYMBOL_VERSION_CONFIG(SkelAnime_DrawFlex, 0x8008A88C, 0x8013682C);

extern int32_t SkelAnime_GetFrameDataLegacy(struct LegacyAnimationHeader* animation, int32_t frame, Vec3s* frameTable);
SYMBOL_VERSION_CONFIG(SkelAnime_GetFrameDataLegacy, 0x8008AAF4, 0x80136A6C);

extern int16_t Animation_GetLimbCountLegacy(struct LegacyAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLimbCountLegacy, 0x8008AEF8, 0x80136E44);

extern int16_t Animation_GetLengthLegacy(struct LegacyAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLengthLegacy, 0x8008AF34, 0x80136E68);

extern int16_t Animation_GetLastFrameLegacy(struct LegacyAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_GetLastFrameLegacy, 0x8008AF70, 0x80136E8C);

extern void SkelAnime_InterpFrameTable(int32_t limbCount, Vec3s* dst, Vec3s* start, Vec3s* target, float weight);
SYMBOL_VERSION_CONFIG(SkelAnime_InterpFrameTable, 0x8008AFB8, 0x80136EB8);

extern void AnimationContext_Reset(struct AnimationContext* animationCtx);
SYMBOL_VERSION_CONFIG(AnimationContext_Reset, 0x8008B438, 0x80137338);

extern void AnimationContext_SetNextQueue(struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(AnimationContext_SetNextQueue, 0x8008B444, 0x80137344);

extern void AnimationContext_DisableQueue(struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(AnimationContext_DisableQueue, 0x8008B464, 0x80137364);

extern AnimationEntry* AnimationContext_AddEntry(struct AnimationContext* animationCtx, AnimationType type);
SYMBOL_VERSION_CONFIG(AnimationContext_AddEntry, 0x8008B48C, 0x8013738C);

extern void AnimationContext_SetLoadFrame(struct GlobalContext* globalCtx, struct LinkAnimationHeader* animation, int32_t frame, int32_t limbCount, Vec3s* frameTable);
SYMBOL_VERSION_CONFIG(AnimationContext_SetLoadFrame, 0x8008B4C4, 0x801373C4);

extern void AnimationContext_SetCopyAll(struct GlobalContext* globalCtx, int32_t vecCount, Vec3s* dst, Vec3s* src);
SYMBOL_VERSION_CONFIG(AnimationContext_SetCopyAll, 0x8008B5C0, 0x80137498);

extern void AnimationContext_SetInterp(struct GlobalContext* globalCtx, int32_t vecCount, Vec3s* base, Vec3s* mod, float weight);
SYMBOL_VERSION_CONFIG(AnimationContext_SetInterp, 0x8008B628, 0x80137500);

extern void AnimationContext_SetCopyTrue(struct GlobalContext* globalCtx, int32_t vecCount, Vec3s* dst, Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(AnimationContext_SetCopyTrue, 0x8008B698, 0x80137570);

extern void AnimationContext_SetCopyFalse(struct GlobalContext* globalCtx, int32_t vecCount, Vec3s* dst, Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(AnimationContext_SetCopyFalse, 0x8008B708, 0x801375E0);

extern void AnimationContext_SetMoveActor(struct GlobalContext* globalCtx, struct Actor* actor, SkelAnime* skelAnime, float arg3);
SYMBOL_VERSION_CONFIG(AnimationContext_SetMoveActor, 0x8008B778, 0x80137650);

extern void AnimationContext_LoadFrame(struct GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_LoadFrame, 0x8008B7D4, 0x801376AC);

extern void AnimationContext_CopyAll(struct GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_CopyAll, 0x8008B804, 0x801376DC);

extern void AnimationContext_Interp(struct GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_Interp, 0x8008B874, 0x8013774C);

extern void AnimationContext_CopyTrue(struct GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_CopyTrue, 0x8008B8D0, 0x801377A8);

extern void AnimationContext_CopyFalse(struct GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_CopyFalse, 0x8008B950, 0x80137828);

extern void AnimationContext_MoveActor(struct GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_MoveActor, 0x8008B9D4, 0x801378AC);

extern void AnimationContext_Update(struct GlobalContext* globalCtx, struct AnimationContext* animationCtx);
SYMBOL_VERSION_CONFIG(AnimationContext_Update, 0x8008BA68, 0x80137958);

extern void SkelAnime_InitLink(struct GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg, struct LinkAnimationHeader* animation, int32_t initFlags, Vec3s* jointTable, Vec3s* morphTable, int32_t limbCount);
//SYMBOL_VERSION_CONFIG(SkelAnime_InitLink, 0x8008BB08, 0x80135F88);
SYMBOL_VERSION_CONFIG(SkelAnime_InitLink, 0x8008BB08, 0x801379F8);

extern void LinkAnimation_SetUpdateFunction(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_SetUpdateFunction, 0x8008BC6C, 0x80137B18);

extern int32_t LinkAnimation_Update(struct GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_Update, 0x8008BCA4, 0x80137B50);

extern int32_t LinkAnimation_Morph(struct GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_Morph, 0x8008BCC8, 0x80137B74);

extern void LinkAnimation_AnimateFrame(struct GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_AnimateFrame, 0x8008BD84, 0x80137C2C);

extern int32_t LinkAnimation_Loop(struct GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_Loop, 0x8008BE60, 0x80137CF8);

extern int32_t LinkAnimation_Once(struct GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_Once, 0x8008BF00, 0x80137D8C);

extern void Animation_SetMorph(struct GlobalContext* globalCtx, SkelAnime* skelAnime, float morphFrames);
SYMBOL_VERSION_CONFIG(Animation_SetMorph, 0x8008BFDC, 0x80137E60);

extern void LinkAnimation_Change(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames);
SYMBOL_VERSION_CONFIG(LinkAnimation_Change, 0x8008C000, 0x80137E84);

extern void LinkAnimation_PlayOnce(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(LinkAnimation_PlayOnce, 0x8008C178, 0x80137FFC);

extern void LinkAnimation_PlayOnceSetSpeed(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float playSpeed);
SYMBOL_VERSION_CONFIG(LinkAnimation_PlayOnceSetSpeed, 0x8008C1D8, 0x8013805C);

extern void LinkAnimation_PlayLoop(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(LinkAnimation_PlayLoop, 0x8008C23C, 0x801380C0);

extern void LinkAnimation_PlayLoopSetSpeed(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float playSpeed);
SYMBOL_VERSION_CONFIG(LinkAnimation_PlayLoopSetSpeed, 0x8008C298, 0x8013811C);

extern void LinkAnimation_CopyJointToMorph(struct GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_CopyJointToMorph, 0x8008C2F8, 0x8013817C);

extern void LinkAnimation_CopyMorphToJoint(struct GlobalContext* globalCtx, SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_CopyMorphToJoint, 0x8008C328, 0x801381AC);

extern void LinkAnimation_LoadToMorph(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float frame);
SYMBOL_VERSION_CONFIG(LinkAnimation_LoadToMorph, 0x8008C358, 0x801381DC);

extern void LinkAnimation_LoadToJoint(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float frame);
SYMBOL_VERSION_CONFIG(LinkAnimation_LoadToJoint, 0x8008C39C, 0x80138220);

extern void LinkAnimation_InterpJointMorph(struct GlobalContext* globalCtx, SkelAnime* skelAnime, float frame);
SYMBOL_VERSION_CONFIG(LinkAnimation_InterpJointMorph, 0x8008C3E0, 0x80138264);

extern void LinkAnimation_BlendToJoint(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation1, float frame1, struct LinkAnimationHeader* animation2, float frame2, float weight, Vec3s* blendTable);
SYMBOL_VERSION_CONFIG(LinkAnimation_BlendToJoint, 0x8008C418, 0x8013829C);

extern void LinkAnimation_BlendToMorph(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation1, float frame1, struct LinkAnimationHeader* animation2, float frame2, float weight, Vec3s* blendTable);
SYMBOL_VERSION_CONFIG(LinkAnimation_BlendToMorph, 0x8008C4B8, 0x8013833C);

extern void LinkAnimation_EndLoop(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(LinkAnimation_EndLoop, 0x8008C558, 0x801383DC);

extern int32_t Animation_OnFrameImpl(SkelAnime* skelAnime, float frame, float updateRate);
SYMBOL_VERSION_CONFIG(Animation_OnFrameImpl, 0x8008C57C, 0x80138400);

extern int32_t LinkAnimation_OnFrame(SkelAnime* skelAnime, float frame);
SYMBOL_VERSION_CONFIG(LinkAnimation_OnFrame, 0x8008C634, 0x801384B8);

extern void SkelAnime_Init(struct GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg, struct LinkAnimationHeader* animation, int32_t initFlags, Vec3s* jointTable, Vec3s* morphTable, int32_t limbCount);
//SYMBOL_VERSION_CONFIG(SkelAnime_Init, 0x8008C684, 0x80136A7C);
SYMBOL_VERSION_CONFIG(SkelAnime_Init, 0x8008C684, 0x801384EC);

extern int32_t SkelAnime_InitFlex(struct GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeaderSeg, AnimationHeader* animation, Vec3s* jointTable, Vec3s* morphTable, int32_t limbCount);
SYMBOL_VERSION_CONFIG(SkelAnime_InitFlex, 0x8008C788, 0x801385A0);

extern int32_t SkelAnime_InitSkin(struct GlobalContext* globalCtx, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg, AnimationHeader* animation);
SYMBOL_VERSION_CONFIG(SkelAnime_InitSkin, 0x8008C894, 0x8013865C);

extern void SkelAnime_SetUpdate(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_SetUpdate, 0x8008C974, 0x801386F4);

extern int32_t SkelAnime_Update(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_Update, 0x8008C9C0, 0x80138740);

extern int32_t SkelAnime_Morph(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_Morph, 0x8008C9E4, 0x80138764);

extern int32_t SkelAnime_MorphTaper(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_MorphTaper, 0x8008CAA4, 0x80138808);

extern void SkelAnime_AnimateFrame(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_AnimateFrame, 0x8008CC2C, 0x80138974);

extern int32_t SkelAnime_LoopFull(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_LoopFull, 0x8008CD74, 0x80138A9C);

extern int32_t SkelAnime_LoopPartial(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_LoopPartial, 0x8008CE14, 0x80138B20);

extern int32_t SkelAnime_Once(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(SkelAnime_Once, 0x8008CEBC, 0x80138BAC);

extern void Animation_ChangeImpl(SkelAnime* skelAnime, AnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames, int8_t taper);
SYMBOL_VERSION_CONFIG(Animation_ChangeImpl, 0x8008CFC0, 0x80138C9C);

extern void Animation_Change(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames);
//SYMBOL_VERSION_CONFIG(SkelAnime_ChangeAnim, 0x8008D17C, 0x801373E8);
SYMBOL_VERSION_CONFIG(Animation_Change, 0x8008D17C, 0x80138E58);

extern void Animation_PlayOnce(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_PlayOnce, 0x8008D1C4, 0x80138EA0);

extern void Animation_MorphToPlayOnce(SkelAnime* skelAnime, AnimationHeader* animation, float morphFrames);
SYMBOL_VERSION_CONFIG(Animation_MorphToPlayOnce, 0x8008D21C, 0x80138EF8);

extern void Animation_PlayOnceSetSpeed(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float playSpeed);
SYMBOL_VERSION_CONFIG(Animation_PlayOnceSetSpeed, 0x8008D278, 0x80138F54);

extern void Animation_PlayLoop(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation);
SYMBOL_VERSION_CONFIG(Animation_PlayLoop, 0x8008D2D4, 0x80138FB0);

extern void Animation_MorphToLoop(SkelAnime* skelAnime, AnimationHeader* animation, float morphFrames);
SYMBOL_VERSION_CONFIG(Animation_MorphToLoop, 0x8008D328, 0x80139004);

extern void Animation_PlayLoopSetSpeed(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float playSpeed);
SYMBOL_VERSION_CONFIG(Animation_PlayLoopSetSpeed, 0x8008D360, 0x8013903C);

extern void Animation_EndLoop(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(Animation_EndLoop, 0x8008D3B8, 0x80139094);

extern void Animation_Reverse(SkelAnime* skelAnime);
SYMBOL_VERSION_CONFIG(Animation_Reverse, 0x8008D3E4, 0x801390C0);

extern void SkelAnime_CopyFrameTableTrue(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(SkelAnime_CopyFrameTableTrue, 0x8008D408, 0x801390E4);

extern void SkelAnime_CopyFrameTableFalse(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(SkelAnime_CopyFrameTableFalse, 0x8008D470, 0x8013914C);

extern void SkelAnime_UpdateTranslation(SkelAnime* skelAnime, struct Vec3f* pos, int16_t angle);
SYMBOL_VERSION_CONFIG(SkelAnime_UpdateTranslation, 0x8008D4DC, 0x801391B8);

extern int32_t Animation_OnFrame(SkelAnime* skelAnime, float frame);
SYMBOL_VERSION_CONFIG(Animation_OnFrame, 0x8008D6A8, 0x80139328);

extern void SkelAnime_Free(SkelAnime* skelAnime, struct GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(SkelAnime_Free, 0x8008D6D0, 0x80139350);

extern void SkelAnime_CopyFrameTable(SkelAnime* skelAnime, Vec3s* dst, Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(SkelAnime_CopyFrameTable, 0x8008D71C, 0x8013939C);

#endif
