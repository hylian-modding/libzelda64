#ifndef LIBZELDA64_Z64INTERNAL_H
#define LIBZELDA64_Z64INTERNAL_H

#include <z64.h>

// this function contains signatures for data which is not declared as extern normally
#if TARGET_GAME == Z64GAME_OOT
extern void Skin_InitAnimatedLimb(PlayState* play, Skin* skin, s32 limbIndex);
#endif
extern void Skin_DrawImpl(Actor* actor, PlayState* play, Skin* skin, SkinPostDraw postDraw, SkinOverrideLimbDraw overrideLimbDraw, s32 setTranslation, s32 arg6, s32 drawFlags);


#endif

