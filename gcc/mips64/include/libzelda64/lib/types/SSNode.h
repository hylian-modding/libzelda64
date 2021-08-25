#ifndef SSNODE_TYPE_H
#define SSNODE_TYPE_H

#include <inttypes.h>

typedef struct SSNode {
    /* 0x00 */ int16_t polyId;
    /* 0x02 */ uint16_t next; // next SSNode index
} SSNode;                     /* sizeof = 0x04 */

#endif
