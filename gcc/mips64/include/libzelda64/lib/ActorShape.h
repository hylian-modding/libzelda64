#ifndef ACTORSHAPE_FUNC_H
#define ACTORSHAPE_FUNC_H

#include "types/ActorShape.h"
#include <inttypes.h>

extern void ActorShape_Init(struct ActorShape* shape, float arg1, void* shadowDrawFunc, float arg3);
asm("ActorShape_Init = 0x8001EC20");
#endif

