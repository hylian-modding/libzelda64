#ifndef FLAGS_FUNC_H
#define FLAGS_FUNC_H

#include "zelda64_version.h"
#include <inttypes.h>

extern int32_t Flags_GetClear(struct GlobalContext* globalCtx, int32_t flag);
SYMBOL_VERSION_CONFIG(Flags_GetClear, 0x80020640, 0x800B5CC4);

#endif
