#ifndef COMMANDBUFFER_H
#define COMMANDBUFFER_H

#include <inttypes.h>
#include "command.h"
#include "commandreturn.h"
#include "commandevent.h"

#define COMMAND_MAX 64
#define COMMANDEVENT_MAX 200 // probably a good amount of extra space for update calls

typedef struct {
    /* 0x000 */ uint16_t commandCount;
    /* 0x002 */ uint16_t eventCount;
    /* 0x004 */ Command commands[COMMAND_MAX];
    /* 0xA04 */ CommandReturn commandReturns[COMMAND_MAX]; // make sure to interpret this data, and wipe it every frame
    /* 0xD04 */ CommandEvent commandEvents[COMMANDEVENT_MAX]; // make sure to interpret this data, and wipe it every frame
} CommandBuffer; /* sizeof = 0x1334 */

extern volatile CommandBuffer* gCmdBuffer;
asm("gCmdBuffer = 0x12345678");
//asm("gCmdBuffer = 0x80680000");

const uint32_t cbSize = sizeof(CommandBuffer);

#endif

