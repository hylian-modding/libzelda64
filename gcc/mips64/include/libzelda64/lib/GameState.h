#ifndef GAMESTATE_FUNC_H
#define GAMESTATE_FUNC_H

#include "types/GameState.h"
#include "zelda64_version.h"

extern void* GameState_Alloc(GameState* gameState, uint32_t size);
SYMBOL_VERSION_CONFIG(GameState_Alloc, 0x800A01B8, 0x80000180);

#endif
