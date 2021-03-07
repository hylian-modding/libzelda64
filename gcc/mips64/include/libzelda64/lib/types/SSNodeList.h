#ifndef SSNODELIST_TYPE_H
#define SSNODELIST_TYPE_H

#include <inttypes.h>

typedef struct SSNodeList {
    /* 0x00 */ uint16_t max;
    /* 0x02 */ uint16_t count;
    /* 0x04 */ struct SSNode* tbl;
    /* 0x08 */ uint8_t* polyCheckTbl;
} SSNodeList; /* sizeof = 0x0C */


#endif

