#ifndef OBJECTCONTEXT_FUNC_H
#define OBJECTCONTEXT_FUNC_H

#include "types/ObjectContext.h"
#include <inttypes.h>

extern int32_t Object_GetIndex(struct ObjectContext* objectCtx, int16_t objectId);
asm("Object_GetIndex = 0x80081628");

int32_t Object_Spawn(struct ObjectContext* objectCtx, int16_t objectId);
asm("Object_Spawn = 0x800812F0");

#endif

