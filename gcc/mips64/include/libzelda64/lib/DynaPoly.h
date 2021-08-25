#ifndef DYNAPOLY_FUNC_H
#define DYNAPOLY_FUNC_H

#include "types/DynaCollisionContext.h"
#include "types/DynaPolyActor.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void DynaPolyActor_Init(DynaPolyActor* actor, DynaPolyMoveFlag flag);
SYMBOL_VERSION_CONFIG(DynaPolyActor_Init, 0x80043480, 0x80000180);

extern int32_t DynaPoly_SetBgActor(struct GlobalContext* globalCtx, DynaCollisionContext* dyna, struct Actor* actor, struct CollisionHeader* colHeader);
SYMBOL_VERSION_CONFIG(DynaPoly_SetBgActor, 0x8003EA74, 0x80000180);

#endif
