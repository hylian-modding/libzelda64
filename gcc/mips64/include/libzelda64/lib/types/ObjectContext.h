#ifndef OBJECTCONTEXT_TYPE_H
#define OBJECTCONTEXT_TYPE_H

#include "ObjectStatus.h"
#include <inttypes.h>

#define OBJECT_EXCHANGE_BANK_MAX 19

typedef struct ObjectContext {
    /* 0x000 */ void* spaceStart;
    /* 0x004 */ void* spaceEnd;
    /* 0x008 */ uint8_t num;
    /* 0x009 */ uint8_t mainKeepNum;
    /* 0x00A */ uint8_t mainKeepIndex;
    /* 0x00B */ uint8_t subKeepIndex;
    /* 0x00C */ ObjectStatus status[OBJECT_EXCHANGE_BANK_MAX];
} ObjectContext; /* sizeof = 0x518 */


#endif

