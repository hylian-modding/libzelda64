# make options
RELEASE_BUILD ?= 1
VRAM_ADDRESS ?= 0x80800000
LIBZ64_PATH ?= ../../include
ULTRALIB_PATH ?= ../../ultralib/include

PROGRAM = commandbuffer

# check for custom compilers
ifeq ($(shell type mips64-o32-gcc >/dev/null 2>/dev/null; echo $$?), 0)
CROSS = mips64-o32-
else ifeq ($(shell type mips64-gcc >/dev/null 2>/dev/null; echo $$?), 0)
CROSS = mips64-
else ifeq ($(shell type mips-linux-gnu-gcc >/dev/null 2>/dev/null; echo $$?), 0)
CROSS = mips-linux-gnu-
else
CROSS = mips64-elf-
endif

# tools 
AS = $(CROSS)as
CC = $(CROSS)gcc
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy

U64_D_FLAGS = -D_LANGUAGE_C -DF3DEX_GBI_2
ML64_D_FLAGS = -D_MLDEBUG -DGAMESTATE_CAVE
GAME_VERSION_D_FLAGS = -DGAME_VERSION_1_0
I_FLAGS = -I$(INCLUDE_DIR) -I$(LIBZ64_PATH) -I$(ULTRALIB_PATH)

ifeq ($(RELEASE_BUILD),1)
OPT_FLAGS = -Os
OPT_FLAGS2 = -mfix4300 -mno-check-zero-division -mframe-header-opt -mdivide-breaks -mno-memcpy -mno-shared -ffreestanding -fno-reorder-blocks -fno-inline-functions -falign-functions=16 -fwrapv -fmerge-all-constants -ffast-math -fmerge-all-constants -fno-stack-protector -fmodulo-sched -fmodulo-sched-allow-regmoves -fira-hoist-pressure -fweb -floop-interchange -fsplit-paths -fallow-store-data-races
else
OPT_FLAGS = -g3
OPT_FLAGS2 = -mfix4300 -mno-check-zero-division -mframe-header-opt -fno-inline-functions -falign-functions=64 -fwrapv
endif

# base dirs
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

# files for build
C_FILES = $(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.c))
O_FILES = $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file).o)
O_FILES_OOT = $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file).o_oot)
O_FILES_MM = $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file).o_mm)

# flags
CFLAGS = -G 0 $(I_FLAGS) $(U64_D_FLAGS) $(ML64_D_FLAGS) $(GAME_VERSION_D_FLAGS) $(OPT_FLAGS) $(OPT_FLAGS2) -std=gnu11 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3 -w
LDFLAGS = -L$(LIBZ64_PATH) -T libzelda64.ld --emit-relocs
MAPNAME := $(BUILD_DIR)/$(PROGRAM).map

TARGET = $(BUILD_DIR)/$(PROGRAM).elf

# rules
default: dirs entry $(TARGET).oot $(TARGET).mm dump_oot dump_mm

dirs:
	mkdir -p $(BUILD_DIR) $(BUILD_DIR)/$(SRC_DIR)
	mkdir -p $(BUILD_DIR)/bin_oot/$(BUILD_DIR)/$(SRC_DIR) $(BUILD_DIR)/bin_mm/$(BUILD_DIR)/$(SRC_DIR)

$(BUILD_DIR)/%.c.o_oot: %.c
	$(CC) -c $< -o $@ $(CFLAGS) -DGAME_OOT

$(BUILD_DIR)/%.c.o_mm: %.c
	$(CC) -c $< -o $@ $(CFLAGS) -DGAME_MM

$(TARGET).oot: $(O_FILES_OOT)
	echo $(O_FILES_OOT) !
	$(LD) $< -o $@ $(LDFLAGS) -Map $(MAPNAME).oot

$(TARGET).mm: $(O_FILES_MM)
	$(LD) $< -o $@ $(LDFLAGS) -Map $(MAPNAME).mm

dump_oot: dirs $(O_FILES_OOT) $(TARGET).oot
	./dumpbinary.sh oot $(CROSS)
	bintots -d $(BUILD_DIR)/bin_oot
	
dump_mm: dirs $(O_FILES_MM) $(TARGET).mm
	./dumpbinary.sh mm $(CROSS)
	bintots -d $(BUILD_DIR)/bin_mm

entry:
	@echo -n "ENTRY_POINT = "$(VRAM_ADDRESS) > entry.ld
	@echo ";" >> entry.ld

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_DIR)/bin_oot $(BUILD_DIR)/bin_mm

.SECONDARY:
.PHONY: clean default
SHELL = /bin/bash -e -o pipefail

