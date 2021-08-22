PROGRAM = commandbuffer
SOURCES =   Actor_DestroyCave.c  Actor_SpawnEntryCave.c            Actor_UpdateCave.c  SkelAnime_DrawFlexLodCave.c	\
			Actor_InitCave.c     Actor_SpawnTransitionActorCave.c  Object_SpawnCave.c  commandbuffer.c				\
			Actor_SpawnCave.c    Actor_SpawnWithAddress.c          Sfx_Cave.c          commandbuffer_offsets.c
OBJECTS = $(SOURCES:.c=.o)
ADDRESS = 0x80800000

CC   = @mips64-gcc
LD   = @mips64-ld

CFLAGS =    -I$(LIBZ64_PATH) -D_LANGUAGE_C -DF3DEX_GBI_2 -D_MLDEBUG -DGAMESTATE_CAVE -G 0 -Ofast	\
            -std=gnu11 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3							        \
            -mdivide-breaks -mno-explicit-relocs -mno-split-addresses -mno-memcpy -mno-check-zero-division -mno-shared -mframe-header-opt	\
			-ffreestanding -fno-reorder-blocks  -w

LDFLAGS = -L$(LIBZ64_PATH) -T $(LIBZ64_LD) --emit-relocs

default: clean entry $(OBJECTS) $(PROGRAM)

$(OBJECTS): %.o: %.c
	@echo CC $<
	$(CC) -c $< -o $@ $(CFLAGS)

$(PROGRAM): $(PROGRAM).c
	@echo CC $<
	$(CC) $(CFLAGS) -c $(PROGRAM).c -o $(PROGRAM).elf
	@echo LD
	$(LD) -o $(PROGRAM).o $(PROGRAM).elf $(LDFLAGS)

entry:
	@echo -n "ENTRY_POINT = "$(ADDRESS) > entry.ld
	@echo ";" >> entry.ld
	@echo "Generated entry.ld"

clean:
	@rm -f *.elf *.o entry.ld
	@rm -f bin/*.bin bin/*.ts
