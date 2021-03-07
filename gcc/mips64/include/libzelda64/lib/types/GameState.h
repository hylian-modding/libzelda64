#ifndef GAMESTATE_TYPE_H
#define GAMESTATE_TYPE_H

#include "Input.h"
#include "TwoHeadArena.h"
#include "GameAlloc.h"

typedef void (*GameStateFunc)(struct GameState* gameState);

typedef struct GameState {
    /* 0x00 */ struct GraphicsContext* gfxCtx;
    /* 0x04 */ GameStateFunc main;
    /* 0x08 */ GameStateFunc destroy;
    /* 0x0C */ GameStateFunc init;
    /* 0x10 */ uint32_t size;
    /* 0x14 */ Input input[4];
    /* 0x74 */ TwoHeadArena tha;
    /* 0x84 */ GameAlloc alloc;
    /* 0x98 */ uint32_t running;
    /* 0x9C */ uint32_t frames;
    /* 0xA0 */ uint32_t disablePrenmi;
} GameState; /* sizeof = 0xA4 */

#endif

