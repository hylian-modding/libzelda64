#ifndef BGCHECK_FUNC_H
#define BHCHECK_FUNC_H

#include <inttypes.h>

extern float BgCheck_EntityRaycastFloor4(struct CollisionContext* colCtx, struct CollisionPoly** outPoly, int32_t* bgId, struct Actor* actor, struct Vec3f* arg4);
asm("BgCheck_EntityRaycastFloor4 = 0x8002F4B8");

extern void Actor_UpdateBgCheckInfo(struct GlobalContext* globalCtx, struct Actor* actor, float arg2, float arg3, float arg4, s32 arg5);
asm("Actor_UpdateBgCheckInfo = 0x80021E6C");

#endif

