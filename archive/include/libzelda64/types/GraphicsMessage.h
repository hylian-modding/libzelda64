#ifndef GRAPHICSMESSAGE_TYPE_H
#define GRAPHICSMESSAGE_TYPE_H

#include <inttypes.h>
// clang-format off
#include <PR/sptask.h>
#include <PR/sched.h>
#include <ultra64.h>
// clang-format on

typedef union {
    struct {
        /* 0x00 */ int16_t type;
    } gen;

    struct {
        /* 0x00 */ int16_t type;
    } done;

    /* 0x00 */ OSScMsg app;
} GraphicsMessage; /* sizeof = 0x20 */

#endif
