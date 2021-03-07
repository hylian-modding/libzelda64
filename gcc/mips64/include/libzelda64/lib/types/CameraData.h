#ifndef CAMERADATA_TYPE_H
#define CAMERADATA_TYPE_H

#include <inttypes.h>

typedef struct CameraData {
    /* 0x02 */ int16_t type;
    /* 0x04 */ int16_t data[7];
} CameraData; /* sizeof = 0x10 */


#endif

