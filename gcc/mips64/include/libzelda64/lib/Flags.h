#ifndef FLAGS_FUNC_H
#define FLAGS_FUNC_H

#include <inttypes.h>

extern int32_t Flags_GetClear(struct GlobalContext* globalCtx, int32_t flag);
asm("Flags_GetClear = 0x80020640");

#endif

