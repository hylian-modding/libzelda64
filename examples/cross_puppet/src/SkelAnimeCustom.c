#include "SkelAnimeCustom.h"

void SkelAnimeCustom_InitLink(GlobalContext* globalCtx, SkelAnime* skelAnime, FlexSkeletonHeader* skeletonHeader,
    LinkAnimationHeader* animation, int32_t flags, Vec3s* jointTable, Vec3s* morphTable, int32_t limbBufCount) {
    int32_t headerJointCount = skeletonHeader->sh.limbCount;
    int32_t limbCount;

    skelAnime->initFlags = flags;
    limbCount = (flags & 2) ? headerJointCount : 1;

    if (flags & 1) {
        limbCount += headerJointCount;
    }
    if (flags & 4) {
        limbCount += headerJointCount;
    }

    skelAnime->limbCount = limbCount;
    skelAnime->dListCount = skeletonHeader->dListCount;

    skelAnime->skeleton = skeletonHeader->sh.segment;

    skelAnime->jointTable = (Vec3s*)ALIGN16((uint32_t)jointTable);
    skelAnime->morphTable = (Vec3s*)ALIGN16((uint32_t)morphTable);

    if (animation != NULL) {
        LinkAnimation_Change(globalCtx, skelAnime, animation, 1.0f, 0.0f, 0.0f, ANIMMODE_LOOP, 0.0f);
    }
}