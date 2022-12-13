#ifndef INPUT_TYPE_H
#define INPUT_TYPE_H

#include <PR/os.h>

typedef struct Input {
    /* 0x00 */ OSContPad cur;
    /* 0x06 */ OSContPad prev;
    /* 0x0C */ OSContPad press; // X/Y store delta from last frame
    /* 0x12 */ OSContPad rel;   // X/Y store adjusted
} Input;                        /* sizeof = 0x18 */

#endif
