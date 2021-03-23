#ifndef DYNAPOLY_FUNC_H
#define DYNAPOLY_FUNC_H

#include "types/DynaPolyActor.h"
#include "types/DynaCollisionContext.h"
#include <inttypes.h>

extern void DynaPolyActor_Init(struct DynaPolyActor* actor, DynaPolyMoveFlag flag);
asm("DynaPolyActor_Init = 0x80043480");

int32_t DynaPoly_SetBgActor(struct GlobalContext* globalCtx, struct DynaCollisionContext* dyna, struct Actor* actor, struct CollisionHeader* colHeader);
asm("DynaPoly_SetBgActor = 0x8003EA74");

#endif

