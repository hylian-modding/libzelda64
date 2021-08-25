#ifndef PLAYER_FUNC_H
#define PLAYER_FUNC_H

#include "types/Player.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern int32_t Health_ChangeBy(struct GlobalContext* globalCtx, int16_t healthChange);
SYMBOL_VERSION_CONFIG(Health_ChangeBy, 0x800720BC, 0x80000180);

#endif
