PROGRAM = commandbuffer
SOURCES = Actor_DestroyCave.c \
Actor_InitCave.c \
Actor_SpawnCave.c \
Actor_SpawnEntryCave.c \
Actor_SpawnTransitionActorCave.c \
Actor_SpawnWithAddress.c \
Actor_SpawnWithParentAndCutsceneCave.c \
Actor_UpdateCave.c \
Object_SpawnCave.c \
Sfx_Cave.c \
SkelAnime_DrawFlexLodCave.c \
SuperDynaPoly_AllocPolyList.c \
SuperDynaPoly_AllocVtxList.c \
SuperDynaSSNodeList_Alloc.c \
commandbuffer.c \
commandbuffer_offsets.c

OBJECTS = $(SOURCES:.c=.o)
ADDRESS = 0x80800000

CC   = @mips64-gcc
LD   = @mips64-ld

CFLAGS =    -I$(LIBZ64_PATH) -D_LANGUAGE_C -DF3DEX_GBI_2 -D_MLDEBUG -DGAMESTATE_CAVE -DGAME_VERSION_1_0 -G 0 -Ofast	\
            -std=gnu11 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3							        \
            -mdivide-breaks -mno-explicit-relocs -mno-split-addresses -mno-memcpy -mno-check-zero-division -mno-shared -mframe-header-opt	\
			-ffreestanding -fno-reorder-blocks  -w

LDFLAGS = -L$(LIBZ64_PATH) -T $(LIBZ64_LD) --emit-relocs

default: dirs $(OBJECTS) $(PROGRAM) dump

dirs:
	mkdir -p bin_oot
	mkdir -p bin_mm

$(OBJECTS): %.o: %.c
	@echo CC $<
	$(CC) -c $< -o $@.oot $(CFLAGS) -DGAME_OOT
	$(CC) -c $< -o $@.mm $(CFLAGS) -DGAME_MM

$(PROGRAM): $(PROGRAM).c
	@echo CC $<
	$(CC) $(CFLAGS) -DGAME_OOT -c $(PROGRAM).c -o $(PROGRAM).elf.oot
	$(CC) $(CFLAGS) -DGAME_MM -c $(PROGRAM).c -o $(PROGRAM).elf.mm
	@echo LD
	$(LD) -o $(PROGRAM).o $(PROGRAM).elf.oot $(LDFLAGS)
	$(LD) -o $(PROGRAM).o $(PROGRAM).elf.mm $(LDFLAGS)

dump: dirs $(OBJECTS) $(PROGRAM)
	./dumpbinary.sh oot
	./dumpbinary.sh mm
	bintots -d bin_oot
	bintots -d bin_mm

clean:
	@rm -f *.elf *.o *.o.oot *.o.mm *.elf.oot *.elf.mm
	@rm -rf bin_oot/*.bin bin_oot/*.ts bin_oot bin_mm/*.bin bin_mm/*.ts bin_mm
