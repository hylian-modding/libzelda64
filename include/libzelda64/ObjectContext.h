#ifndef OBJECTCONTEXT_FUNC_H
#define OBJECTCONTEXT_FUNC_H

#include "types/ObjectContext.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern int32_t Object_GetIndex(struct ObjectContext* objectCtx, int16_t objectId);
SYMBOL_VERSION_CONFIG(Object_GetIndex, 0x80081628, 0x8012F608);

extern int32_t Object_Spawn(struct ObjectContext* objectCtx, int16_t objectId);
SYMBOL_VERSION_CONFIG(Object_Spawn, 0x800812F0, 0x8012F2E0);

#endif
