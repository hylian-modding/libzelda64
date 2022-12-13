#ifndef ZELDA64_VERSION_H
#define ZELDA64_VERSION_H

#ifdef GAME_OOT
#ifdef GAME_VERSION_1_0
#define SYMBOL_VERSION_CONFIG(SYMNAME, OOT10ADDR, MMADDR) asm(#SYMNAME " = " #OOT10ADDR)

// adding these here in the case that we ever add other versions
#elif defined GAME_VERSION_DB /* GAME_VERSION_1_0 */
#warning #SYMNAME " is not defined for Oot Debug! Defaulting to TRAP"
#define SYMBOL_VERSION_CONFIG(SYMNAME, OOT10ADDR, MMADDR) asm(#SYMNAME " = 0x80000180")

#elif defined GAME_VERSION_1_1 /* GAME_VERSION_DB */
#warning #SYMNAME " is not defined for Oot 1.1! Defaulting to TRAP"
#define SYMBOL_VERSION_CONFIG(SYMNAME, OOT10ADDR, MMADDR) asm(#SYMNAME " = 0x80000180")

#elif defined GAME_VERSION_1_2 /* GAME_VERSION_1_1 */
#warning #SYMNAME " is not defined for Oot 1.2! Defaulting to TRAP"
#define SYMBOL_VERSION_CONFIG(SYMNAME, OOT10ADDR, MMADDR) asm(#SYMNAME " = 0x80000180")

#elif defined GAME_VERSION_GC /* GAME_VERSION_1_2 */
#warning #SYMNAME " is not defined for Oot GC! Defaulting to TRAP"
#define SYMBOL_VERSION_CONFIG(SYMNAME, OOT10ADDR, MMADDR) asm(#SYMNAME " = 0x80000180")

#elif defined GAME_VERSION_IQ /* GAME_VERSION_GC */
#warning #SYMNAME " is not defined for Oot IQue! Defaulting to TRAP"
#define SYMBOL_VERSION_CONFIG(SYMNAME, OOT10ADDR, MMADDR) asm(#SYMNAME " = 0x80000180")

#elif defined GAME_VERSION_0_9 /* GAME_VERSION_IQ */
#warning #SYMNAME " is not defined for Oot 0.9! Defaulting to TRAP"
#define SYMBOL_VERSION_CONFIG(SYMNAME, OOT10ADDR, MMADDR) asm(#SYMNAME " = 0x80000180")

#endif /* GAME_VERSION_0_9 */

#elif defined GAME_MM /* GAME_OOT */
#define SYMBOL_VERSION_CONFIG(SYMNAME, OOT10ADDR, MMADDR) asm(#SYMNAME " = " #MMADDR)

#else /* GAME_MM */
#warning #SYMNAME " is not defined for this game (No game? Did you forget to define it?)! Defaulting to TRAP"
#define SYMBOL_VERSION_CONFIG(SYMNAME, OOT10ADDR, MMADDR) asm(#SYMNAME " = 0x80000180")

#endif /* NO GAME? */

#endif
