#ifndef SOUNDSOURCE_TYPE_H
#define SOUNDSOURCE_TYPE_H

#include "Vec3f.h"
#include <inttypes.h>

typedef struct SoundSource {
    /* 0x00 */ int16_t countdown;
    /* 0x02 */ int16_t _pad;
    /* 0x04 */ Vec3f originPos;
    /* 0x10 */ Vec3f relativePos;
} SoundSource; /* sizeof = 0x1C */

#endif
