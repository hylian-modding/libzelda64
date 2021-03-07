#ifndef SOUNDCONTEXT_TYPE_H
#define SOUNDCONTEXT_TYPE_H

typedef struct SoundContext {
    uint8_t seqIndex; // source calls this BGM; index of background music sequence
    uint8_t nightSeqIndex; // source calls this environment
    uint8_t echoLevel;
    //uint8_t _pad;
} SoundContext; /* sizeof = 0x03 */

#endif

