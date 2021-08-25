#ifndef ANIMATIONCONTEXT_FUNC_H
#define ANIMATIONCONTEXT_FUNC_H

#include "types/AnimationContext.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void AnimationContext_SetCopyAll(struct GlobalContext* globalCtx, int32_t vecCount, struct Vec3s* dst, struct Vec3s* src);
SYMBOL_VERSION_CONFIG(AnimationContext_SetCopyAll, 0x8008B5C0, 0x80000180);

extern void AnimationContext_SetCopyTrue(struct GlobalContext* globalCtx, int32_t vecCount, struct Vec3s* dst, struct Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(AnimationContext_SetCopyTrue, 0x8008B698, 0x80000180);

extern void AnimationContext_SetCopyFalse(struct GlobalContext* globalCtx, int32_t vecCount, struct Vec3s* dst, struct Vec3s* src, uint8_t* copyFlag);
SYMBOL_VERSION_CONFIG(AnimationContext_SetCopyFalse, 0x8008B708, 0x80000180);

extern void AnimationContext_SetInterp(struct GlobalContext* globalCtx, int32_t vecCount, struct Vec3s* base, struct Vec3s* mod, float weight);
SYMBOL_VERSION_CONFIG(AnimationContext_SetInterp, 0x8008B628, 0x80000180);

#endif
