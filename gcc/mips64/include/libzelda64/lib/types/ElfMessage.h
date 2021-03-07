#ifndef ELFMESSAGE_TYPE_H
#define ELFMESSAGE_TYPE_H

#include <inttypes.h>

typedef struct ElfMessage {
    /* 0x00 */ uint8_t byte0;
    /* 0x01 */ uint8_t byte1;
    /* 0x02 */ uint8_t byte2;
    /* 0x03 */ uint8_t byte3;
} ElfMessage; /* sizeof = 0x04 */


#endif

