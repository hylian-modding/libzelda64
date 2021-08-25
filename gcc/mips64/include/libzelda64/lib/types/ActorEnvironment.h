#ifndef ACTORENVIRONMENT_TYPE_H
#define ACTORENVIRONMENT_TYPE_H

#include <inttypes.h>

typedef struct ActorEnvironment {
    /* 0x00 */ uint32_t swch;
    /* 0x04 */ uint32_t tempSwch;
    /* 0x08 */ uint32_t checkSwch;
    /* 0x0C */ uint32_t checkTempSwch;
    /* 0x10 */ uint32_t chest;
    /* 0x14 */ uint32_t clear;
    /* 0x18 */ uint32_t tempClear;
    /* 0x1C */ uint32_t collect;
    /* 0x20 */ uint32_t tempCollect;
} ActorEnvironment; /* sizeof = 0x24 */


#endif
