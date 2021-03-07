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
#include <inttypes.h>

extern int32_t Collider_SetCylinder(struct GlobalContext* globalCtx, struct ColliderCylinder* collider, struct Actor* actor, struct ColliderCylinderInit* src);
asm("Collider_SetCylinder = 0x8004ACEC");

extern int32_t Collider_DestroyCylinder(struct GlobalContext* globalCtx, struct ColliderCylinder* collider);
asm("Collider_DestroyCylinder = 0x8004ABCC");

extern int32_t Collider_InitCylinder(struct GlobalContext* globalCtx, struct ColliderCylinder* collider);
asm("Collider_InitCylinder = 0x8004AB7C");

#endif