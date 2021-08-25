#ifndef TRANSITIONCONTEXT_TYPE_H
#define TRANSITIONCONTEXT_TYPE_H

#include "TransitionType.h"
#include <inttypes.h>

typedef void* (*TransitionFunc0)(void* transition);
typedef void (*TransitionFunc1)(void* transition);
typedef void (*TransitionFunc2)(void* transition, int32_t A1);
typedef void (*TransitionFunc3)(void* transition, Gfx** gfxP);
typedef void (*TransitionFunc4)(void* transition, uint32_t A1);
typedef int32_t (*TransitionFunc5)(void* transition);

typedef struct TransitionContext {
    /* 0x000 */ TransitionType fade;
    /* 0x228 */ int transitionType;
    /* 0x22C */ TransitionFunc0 init;
    /* 0x230 */ TransitionFunc1 destroy;
    /* 0x234 */ TransitionFunc2 update;
    /* 0x238 */ TransitionFunc3 draw;
    /* 0x23C */ TransitionFunc1 start;
    /* 0x240 */ TransitionFunc2 setType;
    /* 0x244 */ TransitionFunc4 setColor;
    /* 0x248 */ TransitionFunc4 setEnvColor;
    /* 0x24C */ TransitionFunc5 isDone;
} TransitionContext; /* sizeof = 0x250 */


#endif
