#ifndef COMMANDBUFFER_H
#define COMMANDBUFFER_H

#include <inttypes.h>
#include "command.h"
#include "commandreturn.h"
#include "commandactor.h"

#define COMMAND_MAX 64
#define COMMANDACTOR_MAX 383 // probably a good amount of extra space for update calls

typedef struct {
    /* 0x000 */ uint32_t commandCount;
    /* 0x004 */ Command commands[COMMAND_MAX];
    /* 0x904 */ CommandReturn commandReturns[COMMAND_MAX]; // make sure to interpret this data, and wipe it every frame
    /* 0xC04 */ CommandActor commandActors[COMMANDACTOR_MAX]; // make sure to interpret this data, and wipe it every frame
} CommandBuffer; /* sizeof = 0x17FC */

extern CommandBuffer* cmdBuffer;
asm("cmdBuffer = 0x806B0000");

#endif

