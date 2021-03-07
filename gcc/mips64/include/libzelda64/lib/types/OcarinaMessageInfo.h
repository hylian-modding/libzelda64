#ifndef OCARINAMESSAGEINFO_TYPE_H
#define OCARINAMESSAGEINFO_TYPE_H

#include <inttypes.h>

typedef struct OcarinaMessageInfo {
    /* 0x00 */ uint8_t button;
    /* 0x01 */ uint8_t status;
    /* 0x02 */ uint8_t locate;
} OcarinaMessageInfo; /* sizeof = 0x03 */

#endif

