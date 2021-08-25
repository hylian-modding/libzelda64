#ifndef ACTORSHAPE_FUNC_H
#define ACTORSHAPE_FUNC_H

#include "types/ActorShape.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern void ActorShape_Init(struct ActorShape* shape, float arg1, void* shadowDrawFunc, float arg3);
SYMBOL_VERSION_CONFIG(ActorShape_Init, 0x8001EC20, 0x80000180);

#endif
