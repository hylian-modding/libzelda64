#include "commandbuffer.h"
#include <libzelda64/lib/Macros.h>

const uint32_t Command_Max = COMMAND_MAX;
const uint32_t CommandEvent_Max = COMMANDEVENT_MAX;
const uint32_t CommandCount_Offset = OFFSETOF(CommandBuffer, commandCount);
const uint32_t EventCount_Offset = OFFSETOF(CommandBuffer, eventCount);
const uint32_t Commands_Offset = OFFSETOF(CommandBuffer, commands);
const uint32_t CommandReturns_Offset = OFFSETOF(CommandBuffer, commandReturns);
const uint32_t CommandEvents_Offset = OFFSETOF(CommandBuffer, commandEvents);
const uint32_t Commands_Sizeof = sizeof(((CommandBuffer*)0)->commands);
const uint32_t CommandReturns_Sizeof = sizeof(((CommandBuffer*)0)->commandReturns);
const uint32_t CommandEvents_Sizeof = sizeof(((CommandBuffer*)0)->commandEvents);
const uint32_t Command_Sizeof = sizeof(Command);
const uint32_t CommandReturn_Sizeof = sizeof(CommandReturn);
const uint32_t CommandEvent_Sizeof = sizeof(CommandEvent);
