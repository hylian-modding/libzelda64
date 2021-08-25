#ifndef DYNASSNODELIST_TYPE_H
#define DYNASSNODELIST_TYPE_H

#include <inttypes.h>

typedef struct DynaSSNodeList {
    /* 0x00 */ struct SSNode* tbl;
    /* 0x04 */ int32_t count;
    /* 0x08 */ int32_t max;
} DynaSSNodeList; /* sizeof = 0x0C */

#endif
