#ifndef ANIMATIONCONTEXT_FUNC_H
#define ANIMATIONCONTEXT_FUNC_H

#include "types/AnimationContext.h"
#include "types/AnimationEntry.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void AnimationContext_Reset(AnimationContext* animationCtx);
SYMBOL_VERSION_CONFIG(AnimationContext_Reset, 0x8008B438, 0x801358C8);

extern void AnimationContext_SetNextQueue(GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(AnimationContext_SetNextQueue, 0x8008B444, 0x801358D4);

extern void AnimationContext_DisableQueue(GlobalContext* globalCtx);
SYMBOL_VERSION_CONFIG(AnimationContext_DisableQueue, 0x8008B464, 0x801358F4);

extern AnimationEntry* AnimationContext_AddEntry(AnimationContext* animationCtx, AnimationType type);
SYMBOL_VERSION_CONFIG(AnimationContext_AddEntry, 0x8008B48C, 0x8013591C);

extern void AnimationContext_SetLoadFrame(GlobalContext* globalCtx, LinkAnimationHeader* animation, int32_t frame, int32_t limbCount, Vec3s* frameTable);
SYMBOL_VERSION_CONFIG(AnimationContext_SetLoadFrame, 0x8008B4C4, 0x80135954);

extern void AnimationContext_SetCopyAll(GlobalContext* globalCtx, int32_t vecCount, Vec3s* dst, Vec3s* src);
SYMBOL_VERSION_CONFIG(AnimationContext_SetCopyAll, 0x8008B5C0, 0x80135A28);

extern void AnimationContext_SetInterp(GlobalContext* globalCtx, int32_t vecCount, Vec3s* base, Vec3s* mod, float weight);
SYMBOL_VERSION_CONFIG(AnimationContext_SetInterp, 0x8008B628, 0x80135A90);

extern void AnimationContext_SetCopyTrue(GlobalContext* globalCtx, int32_t vecCount, Vec3s* dst, Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(AnimationContext_SetCopyTrue, 0x8008B698, 0x80135B00);

extern void AnimationContext_SetCopyFalse(GlobalContext* globalCtx, int32_t vecCount, Vec3s* dst, Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(AnimationContext_SetCopyFalse, 0x8008B708, 0x80135B70);

extern void AnimationContext_SetMoveActor(GlobalContext* globalCtx, Actor* actor, SkelAnime* skelAnime, float arg3);
SYMBOL_VERSION_CONFIG(AnimationContext_SetMoveActor, 0x8008B778, 0x80135BE0);

extern void AnimationContext_LoadFrame(GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_LoadFrame, 0x8008B7D4, 0x80135C3C);

extern void AnimationContext_CopyAll(GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_CopyAll, 0x8008B804, 0x80135C6C);

extern void AnimationContext_Interp(GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_Interp, 0x8008B874, 0x80135CDC);

extern void AnimationContext_CopyTrue(GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_CopyTrue, 0x8008B8D0, 0x80135D38);

extern void AnimationContext_CopyFalse(GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_CopyFalse, 0x8008B950, 0x80135DB8);

extern void AnimationContext_MoveActor(GlobalContext* globalCtx, AnimationEntryData* data);
SYMBOL_VERSION_CONFIG(AnimationContext_MoveActor, 0x8008B9D4, 0x80135E3C);

extern void AnimationContext_Update(GlobalContext* globalCtx, AnimationContext* animationCtx);
SYMBOL_VERSION_CONFIG(AnimationContext_Update, 0x8008BA68, 0x80135EE8);

extern void Animation_SetMorph(GlobalContext* globalCtx, SkelAnime* skelAnime, float morphFrames);
SYMBOL_VERSION_CONFIG(Animation_SetMorph, 0x8008BFDC, 0x801363F0);

#endif
