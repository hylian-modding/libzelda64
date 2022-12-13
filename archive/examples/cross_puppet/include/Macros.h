#ifndef _PUPPET_MACROS_H
#define _PUPPET_MACROS_H

#define baseToPointer(offset)(*((uint32_t*)(thisx->basePointer + offset)))
#define obtainAlias(offset)((uint32_t)thisx->basePointer + offset)
#define RESET_ENV_TO_TUNIC() gDPSetEnvColor(POLY_OPA_DISP++, ((thisx)->syncInfo).colorTunic.r, ((thisx)->syncInfo).colorTunic.g, ((thisx)->syncInfo).colorTunic.b, ((thisx)->syncInfo).colorTunic.a)

#endif