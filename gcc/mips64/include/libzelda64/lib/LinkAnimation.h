#ifndef LINKANIMATION_FUNC_H
#define LINKANIMATION_FUNC_H

#include "types/LinkAnimationHeader.h"
#include <inttypes.h>

// SkelAnime_ChangeLinkAnim / Skeleton_Info_Rom_init on Poe's sheet (Decomp changed name, not in ovl)
extern void LinkAnimation_Change(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames);
asm("LinkAnimation_Change = 0x8008C000");

// func_800A3BC0 / Skeleton_Info_Rom_anime_play on Poe's sheet (Decomp named, not in ovl)
extern void LinkAnimation_Update(struct GlobalContext* globalCtx, struct SkelAnime* skelAnime);
asm("LinkAnimation_Update = 0x8008BCA4");

#endif

