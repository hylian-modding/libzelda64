#ifndef GRAPHICSMESSAGE_TYPE_H
#define GRAPHICSMESSAGE_TYPE_H

#include <libultra/ultra64.h>
#include <libultra/PR/sptask.h>
#include <libultra/PR/sched.h>
#include <inttypes.h>

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

