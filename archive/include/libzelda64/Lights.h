#ifndef LIGHTS_FUNC_H
#define LIGHTS_FUNC_H

#include "types/LightNode.h"
#include "types/Lights.h"
#include "zelda64_version.h"

extern void Lights_BindAll(Lights* lights, LightNode* listHead, struct Vec3f* vec);
SYMBOL_VERSION_CONFIG(Lights_BindAll, 0x80066298, 0x80000180);

extern void Lights_Draw(Lights* lights, struct GraphicsContext* gfxCtx);
SYMBOL_VERSION_CONFIG(Lights_Draw, 0x80065D60, 0x80000180);

#endif
