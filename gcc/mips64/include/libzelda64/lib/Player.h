#ifndef PLAYER_FUNC_H
#define PLAYER_FUNC_H

#include <inttypes.h>
#include "types/Player.h"

extern int32_t Health_ChangeBy(struct GlobalContext* globalCtx, int16_t healthChange);
asm("Health_ChangeBy = 0x800720BC");

#endif

