#ifndef COLLIDER_FUNCS_H
#define COLLIDER_FUNCS_H

#include "types/Collider.h"
#include "types/ColliderBump.h"
#include "types/ColliderBumpInit.h"
#include "types/ColliderCylinder.h"
#include "types/ColliderCylinderInit.h"
#include "types/ColliderInfo.h"
#include "types/ColliderInfoInit.h"
#include "types/ColliderInit.h"
#include "types/ColliderInitToActor.h"
#include "types/ColliderInitType1.h"
#include "types/ColliderQuad.h"
#include "types/ColliderQuadDim.h"
#include "types/ColliderQuadDimInit.h"
#include "types/ColliderTouch.h"
#include "types/CollisionHeader.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern int32_t Collider_SetCylinder(struct GlobalContext* globalCtx, ColliderCylinder* collider, struct Actor* actor, ColliderCylinderInit* src);
SYMBOL_VERSION_CONFIG(Collider_SetCylinder, 0x8004ACEC, 0x80000180);

extern int32_t Collider_DestroyCylinder(struct GlobalContext* globalCtx, ColliderCylinder* collider);
SYMBOL_VERSION_CONFIG(Collider_DestroyCylinder, 0x8004ABCC, 0x80000180);

extern int32_t Collider_InitCylinder(struct GlobalContext* globalCtx, ColliderCylinder* collider);
SYMBOL_VERSION_CONFIG(Collider_InitCylinder, 0x8004AB7C, 0x80000180);

extern void Collider_UpdateCylinder(struct Actor* actor, ColliderCylinder* collider);
SYMBOL_VERSION_CONFIG(Collider_UpdateCylinder, 0x80050B00, 0x80000180);

extern int32_t CollisionCheck_SetAT(struct GlobalContext* globalCtx, struct CollisionCheckContext* colChkCtx, Collider* collider);
SYMBOL_VERSION_CONFIG(CollisionCheck_SetAT, 0x8004BD50, 0x80000180);

extern int32_t CollisionCheck_SetAC(struct GlobalContext* globalCtx, struct CollisionCheckContext* colChkCtx, Collider* collider);
SYMBOL_VERSION_CONFIG(CollisionCheck_SetAC, 0x8004BF40, 0x80000180);

extern int32_t CollisionCheck_SetOC(struct GlobalContext* globalCtx, struct CollisionCheckContext* colChkCtx, Collider* collider);
SYMBOL_VERSION_CONFIG(CollisionCheck_SetOC, 0x8004C130, 0x80000180);

extern void CollisionHeader_GetVirtual(void* colHeader, struct CollisionHeader** dest);
SYMBOL_VERSION_CONFIG(CollisionHeader_GetVirtual, 0x80033EF4, 0x80000180);

extern int32_t Collider_InitJntSph(struct GlobalContext* globalCtx, struct ColliderJntSph* collider);
SYMBOL_VERSION_CONFIG(Collider_InitJntSph, 0x8004A484, 0x80000180);

extern int32_t Collider_SetJntSph(struct GlobalContext* globalCtx, struct ColliderJntSph* dest, struct Actor* actor, struct ColliderJntSphInit* src, struct ColliderJntSphElement* elements);
SYMBOL_VERSION_CONFIG(Collider_SetJntSph, 0x8004A874, 0x80000180);

extern struct DamageTable* DamageTable_Get(int32_t index);
SYMBOL_VERSION_CONFIG(DamageTable_Get, 0x80049E10, 0x80000180);

extern void CollisionCheck_SetInfo2(struct CollisionCheckInfo* info, struct DamageTable* damageTable, struct CollisionCheckInfoInit2* init);
SYMBOL_VERSION_CONFIG(CollisionCheck_SetInfo2, 0x80050370, 0x80000180);

extern int32_t Collider_DestroyJntSph(struct GlobalContext* globalCtx, struct ColliderJntSph* collider);
SYMBOL_VERSION_CONFIG(Collider_DestroyJntSph, 0x8004A550, 0x80000180);

#endif