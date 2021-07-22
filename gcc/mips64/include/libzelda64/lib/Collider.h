#ifndef COLLIDER_FUNCS_H
#define COLLIDER_FUNCS_H

#include "types/Collider.h"
#include "types/ColliderInit.h"
#include "types/ColliderInfo.h"
#include "types/ColliderInfoInit.h"
#include "types/ColliderCylinder.h"
#include "types/ColliderCylinderInit.h"
#include "types/ColliderInitToActor.h"
#include "types/ColliderInitType1.h"
#include "types/ColliderQuad.h"
#include "types/ColliderQuadDim.h"
#include "types/ColliderQuadDimInit.h"
#include "types/ColliderTouch.h"
#include "types/ColliderBump.h"
#include "types/ColliderBumpInit.h"
#include "types/CollisionHeader.h"
#include <inttypes.h>

extern int32_t Collider_SetCylinder(struct GlobalContext* globalCtx, struct ColliderCylinder* collider, struct Actor* actor, struct ColliderCylinderInit* src);
asm("Collider_SetCylinder = 0x8004ACEC");

extern int32_t Collider_DestroyCylinder(struct GlobalContext* globalCtx, struct ColliderCylinder* collider);
asm("Collider_DestroyCylinder = 0x8004ABCC");

extern int32_t Collider_InitCylinder(struct GlobalContext* globalCtx, struct ColliderCylinder* collider);
asm("Collider_InitCylinder = 0x8004AB7C");

extern void Collider_UpdateCylinder(struct Actor* actor, struct ColliderCylinder* collider);
asm("Collider_UpdateCylinder = 0x80050B00");

extern int32_t CollisionCheck_SetAT(struct GlobalContext* globalCtx, struct CollisionCheckContext* colChkCtx, struct Collider* collider);
asm("CollisionCheck_SetAT = 0x8004BD50");

extern int32_t CollisionCheck_SetAC(struct GlobalContext* globalCtx, struct CollisionCheckContext* colChkCtx, struct Collider* collider);
asm("CollisionCheck_SetAC = 0x8004BF40");

extern int32_t CollisionCheck_SetOC(struct GlobalContext* globalCtx, struct CollisionCheckContext* colChkCtx, struct Collider* collider);
asm("CollisionCheck_SetOC = 0x8004C130");

extern void CollisionHeader_GetVirtual(void* colHeader, struct CollisionHeader** dest);
asm("CollisionHeader_GetVirtual = 0x80033EF4");

extern int32_t Collider_InitJntSph(struct GlobalContext* globalCtx, struct ColliderJntSph* collider);
asm("Collider_InitJntSph = 0x8004A484");

extern int32_t Collider_SetJntSph(struct GlobalContext* globalCtx, struct ColliderJntSph* dest, struct Actor* actor, struct ColliderJntSphInit* src, struct ColliderJntSphElement* elements);
asm("Collider_SetJntSph = 0x8004A874");

extern struct DamageTable* DamageTable_Get(int32_t index);
asm("DamageTable_Get = 0x80049E10");

extern void CollisionCheck_SetInfo2(struct CollisionCheckInfo* info, struct DamageTable* damageTable, struct CollisionCheckInfoInit2* init);
asm("CollisionCheck_SetInfo2 = 0x80050370");

extern int32_t Collider_DestroyJntSph(struct GlobalContext* globalCtx, struct ColliderJntSph* collider);
asm("Collider_DestroyJntSph = 0x8004A550");

#endif