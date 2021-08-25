#ifndef GAMESTATE_TYPE_H
#define GAMESTATE_TYPE_H

#include "GameAlloc.h"
#include "GraphicsContext.h"
#include "Input.h"
#include "TwoHeadArena.h"

typedef void (*GameStateFunc)(struct GameState* gameState);

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
typedef struct {
    /* 0x00 */ GraphicsContext* gfxCtx;
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

#else /* GAME_VERSION_1_0 */
#warning "GameState is not defined for this game version!"
#endif
#elif defined GAME_MM /* GAME_OOT */
typedef struct {
    /* 0x00 */ GraphicsContext* gfxCtx;
    /* 0x04 */ GameStateFunc main;
    /* 0x08 */ GameStateFunc destroy;
    /* 0x0C */ GameStateFunc init;
    /* 0x10 */ uint32_t size;
    /* 0x14 */ Input input[4];
    /* 0x74 */ TwoHeadArena tha;
    /* 0x84 */ GameAlloc alloc;
    /* 0x98 */ char pad98[0x3];
    /* 0x9B */ uint8_t running; // If 0, switch to next game state
    /* 0x9C */ uint32_t frames;
    /* 0xA0 */ char padA0[0x2];
    /* 0xA2 */ uint8_t framerateDivisor; // game speed?
    /* 0xA3 */ uint8_t unkA3;
} GameState; /* sizeof = 0xA4 */
#endif                /* GAME_MM */
#endif
