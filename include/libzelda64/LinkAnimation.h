#ifndef LINKANIMATION_FUNC_H
#define LINKANIMATION_FUNC_H

#include "types/LinkAnimationHeader.h"
#include "zelda64_version.h"
#include <inttypes.h>

extern int32_t LinkAnimation_Update(struct GlobalContext* globalCtx, SkelAnime* skelAnime);
//SYMBOL_VERSION_CONFIG(LinkAnimation_Update, 0x8008BCA4, 0x80137B50);
SYMBOL_VERSION_CONFIG(LinkAnimation_Update, 0x8008BCA4, 0x801360E0);

extern void LinkAnimation_Change(struct GlobalContext* globalCtx, SkelAnime* skelAnime, struct LinkAnimationHeader* animation, float playSpeed, float startFrame, float endFrame, uint8_t mode, float morphFrames);
//SYMBOL_VERSION_CONFIG(LinkAnimation_Change, 0x8008C000, 0x80137E84);
SYMBOL_VERSION_CONFIG(LinkAnimation_Change, 0x8008C000, 0x80136414);

#endif
