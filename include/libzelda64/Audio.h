#ifndef AUDIO_FUNC_H
#define AUDIO_FUNC_H

#include "zelda64_version.h"
#include <inttypes.h>

extern void Audio_PlaySoundAtPosition(struct GlobalContext* globalCtx, struct Vec3f* pos, int32_t duration, uint16_t id);
SYMBOL_VERSION_CONFIG(Audio_PlaySoundAtPosition, 0x80058FF8, 0x800F0568);

extern void Audio_PlaySoundGeneral(uint16_t sfxId, struct Vec3f* a1, uint8_t a2, float* a3, float* a4, float* a5);
SYMBOL_VERSION_CONFIG(Audio_PlaySoundGeneral, 0x800C806C, 0x8019F0C8);

extern void Audio_SetBGM(uint32_t bgmId);
SYMBOL_VERSION_CONFIG(Audio_SetBGM, 0x800CAA70, 0x801A400C);

extern void Audio_PlayActorSound2(struct Actor* actor, uint16_t sfxId);
SYMBOL_VERSION_CONFIG(Audio_PlayActorSound2, 0x80022FD0, 0x800B8EC8);

#define NA_BGM_STOP 0x100000FF

#endif
