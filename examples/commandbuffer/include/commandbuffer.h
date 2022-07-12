#ifndef COMMANDBUFFER_H
#define COMMANDBUFFER_H

#include <libzelda64.h>
#include "command.h"
#include "commandreturn.h"
#include "commandevent.h"

#define COMMAND_MAX 64
#define COMMANDEVENT_MAX 200 // probably a good amount of extra space for update calls
#define SUPER_OBJECT_EXCHANGE_BANK_MAX 48

typedef struct {
    /* 0x00 */ int16_t id;
    /* 0x04 */ void* segment;
    /* 0x08 */ DmaRequest dmaRequest;
    /* 0x28 */ OSMesgQueue loadQueue;
    /* 0x40 */ OSMesg loadMsg;
} SuperObjectStatus; /* sizeof = 0x44 */

typedef struct {
    /* 0x0000 */ void* spaceStart;
    /* 0x0004 */ void* spaceEnd; // original name: "endSegment"
    /* 0x0008 */ uint8_t num; // number of objects in bank
    /* 0x0009 */ uint8_t unk_09;
    /* 0x000A */ uint8_t mainKeepIndex; // "gameplay_keep" index in bank
    /* 0x000B */ uint8_t subKeepIndex; // "gameplay_field_keep" or "gameplay_dangeon_keep" index in bank
    /* 0x000C */ SuperObjectStatus status[SUPER_OBJECT_EXCHANGE_BANK_MAX];
} SuperObjectContext; /* sizeof = 0xCCC */

typedef struct {
    /* 0x0000 */ uint16_t commandCount;
    /* 0x0002 */ uint16_t eventCount;
    /* 0x0004 */ Command commands[COMMAND_MAX];
    /* 0x0A04 */ CommandReturn commandReturns[COMMAND_MAX]; // make sure to interpret this data, and wipe it every frame
    /* 0x0D04 */ CommandEvent commandEvents[COMMANDEVENT_MAX]; // make sure to interpret this data, and wipe it every frame
} CommandBuffer; /* sizeof = 0x1334 */

extern volatile CommandBuffer* gCmdBuffer;
asm("gCmdBuffer = 0x12345678");
//asm("gCmdBuffer = 0x80680000");

const uint32_t cbSize = sizeof(CommandBuffer);

#endif

