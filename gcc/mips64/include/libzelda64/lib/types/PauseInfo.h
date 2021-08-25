#ifndef PAUSEINFO_TYPE_H
#define PAUSEINFO_TYPE_H

#include <inttypes.h>

typedef struct PauseInfo {
    /* 0x00 */ int32_t flag;
    /* 0x04 */ int32_t timer;
} PauseInfo; /* sizeof = 0x08 */

#endif
