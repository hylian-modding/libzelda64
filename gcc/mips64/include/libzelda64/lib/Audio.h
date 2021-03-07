#ifndef AUDIO_FUNC_H
#define AUDIO_FUNC_H

#include <inttypes.h>

extern void Audio_PlaySoundAtPosition(struct GlobalContext* globalCtx, struct Vec3f* pos, int32_t duration, uint16_t id);
asm("Audio_PlaySoundAtPosition = 0x80058FF8");

#endif

