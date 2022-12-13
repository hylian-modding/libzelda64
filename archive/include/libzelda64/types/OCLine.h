#ifndef OCLINE_TYPE_H
#define OCLINE_TYPE_H

#include "Linef.h"
#include <inttypes.h>

typedef struct OCLine {
    /* 0x00 */ Linef line;
    /* 0x18 */ uint16_t ocFlags;
} OCLine; /* sizeof = 0x1C */


#endif
