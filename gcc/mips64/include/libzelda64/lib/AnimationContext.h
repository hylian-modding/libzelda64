#ifndef ANIMATIONCONTEXT_FUNC_H
#define ANIMATIONCONTEXT_FUNC_H

#include "types/AnimationContext.h"
#include <inttypes.h>

extern void AnimationContext_SetCopyAll(struct GlobalContext* globalCtx, int32_t vecCount, struct Vec3s* dst, struct Vec3s* src);
asm("AnimationContext_SetCopyAll = 0x8008B5C0");

extern void AnimationContext_SetCopyTrue(struct GlobalContext* globalCtx, int32_t vecCount, struct Vec3s* dst, struct Vec3s* src, uint8_t* copyFlag);
asm("AnimationContext_SetCopyTrue = 0x8008B698");

extern void AnimationContext_SetCopyFalse(struct GlobalContext* globalCtx, int32_t vecCount, struct Vec3s* dst, struct Vec3s* src, uint8_t* copyFlag);
asm("AnimationContext_SetCopyFalse = 0x8008B708");

extern void AnimationContext_SetInterp(struct GlobalContext* globalCtx, int32_t vecCount, struct Vec3s* base, struct Vec3s* mod, float weight);
asm("AnimationContext_SetInterp = 0x8008B628");

#endif

