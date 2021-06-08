#ifndef COMMANDRETURN_H
#define COMMANDRETURN_H

#include <inttypes.h>
#include "command.h"

typedef struct {
    /* 0x00 */ struct Actor* actor;
} CommandReturnData_ActorSpawn; /* sizeof = 0x04 */

typedef struct {
    /* 0x00 */ uint32_t value;
} CommandReturnData_ArbitraryFunction; /* sizeof = 0x04 */

typedef struct {
    /* 0x00 */ uint16_t sfxId;
} CommandReturnData_Sfx; /* sizeof = 0x02 */

typedef union {
    CommandReturnData_ActorSpawn actorSpawn;
    CommandReturnData_Sfx sfx;
    CommandReturnData_ArbitraryFunction arbFn;
} CommandReturnData; /* sizeof = 0x04 */

typedef struct {
    /* 0x00 */ uint32_t type;
    /* 0x04 */ uint32_t uuid;
    /* 0x08 */ CommandReturnData data;
} CommandReturn; /* sizeof = 0x0C */

#endif

