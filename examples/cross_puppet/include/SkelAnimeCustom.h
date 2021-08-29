#ifndef PUPPET_SKELANIMECUSTOM_H
#define PUPPET_SKELANIMECUSTOM_H

#include <libzelda64.h>

extern void SkelAnimeCustom_InitLink(GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeader,
    LinkAnimationHeader* animation, int32_t flags, Vec3s* jointTable, Vec3s* morphTable, int32_t limbBufCount);



#endif

