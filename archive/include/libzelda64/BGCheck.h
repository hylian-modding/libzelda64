#ifndef BGCHECK_FUNC_H
#define BHCHECK_FUNC_H

#include "zelda64_version.h"
#include <inttypes.h>

extern float BgCheck_EntityRaycastFloor4(struct CollisionContext* colCtx, struct CollisionPoly** outPoly, int32_t* bgId, struct Actor* actor, struct Vec3f* arg4);
SYMBOL_VERSION_CONFIG(BgCheck_EntityRaycastFloor4, 0x8002F4B8, 0x80000180);

extern void Actor_UpdateBgCheckInfo(struct GlobalContext* globalCtx, struct Actor* actor, float arg2, float arg3, float arg4, int32_t arg5);
SYMBOL_VERSION_CONFIG(Actor_UpdateBgCheckInfo, 0x80021E6C, 0x80000180);

extern int32_t BgCheck_EntityLineTest1(
    struct CollisionContext* colCtx, struct Vec3f* posA, struct Vec3f* posB, struct Vec3f* posResult, struct CollisionPoly** outPoly, int32_t chkWall, int32_t chkFloor, int32_t chkCeil,
    int32_t chkOneFace, int32_t* bgId);
SYMBOL_VERSION_CONFIG(BgCheck_EntityLineTest1, 0x800308B4, 0x80000180);

#endif
