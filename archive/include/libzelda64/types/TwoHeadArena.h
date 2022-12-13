#ifndef TWOHEADARENA_TYPE_H
#define TWOHEADARENA_TYPE_H

#include <inttypes.h>
#include <PR/gbi.h>

typedef struct TwoHeadArena {
    /* 0x00 */ uint32_t size;
    /* 0x04 */ void* bufp;

    union {
        struct {
            /* 0x08 */ void* head;
            /* 0x0C */ void* tail;
        };

        struct {
            /* 0x08 */ Gfx* p;
            /* 0x0C */ Gfx* d;
        };
    };
} TwoHeadArena, TwoHeadGfxArena; /* sizeof = 0x10 */


#endif
