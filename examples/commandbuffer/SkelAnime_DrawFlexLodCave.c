#include <inttypes.h>
#include <libzelda64/lib/types/GlobalContext.h>
#include <libzelda64/lib/SkelAnime.h>
#include "commandbuffer.h"

/* 80089710?
    I have no idea what the purpose of this function is
    Glank hooks into this at the point that the stack resets at the end of SkelAnime_DrawFlexLod
    Do we need this??
*/
void SkelAnime_DrawFlexLodHook(void) {

}

