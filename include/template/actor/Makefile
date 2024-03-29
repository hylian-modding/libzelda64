# Directory Structure
SRC_DIR = src
BUILD_DIR = build
DIST_DIR = dist

# Build Setup
INPUT = template
SEGMENT = 0x80800000
PARTS = $(INPUT).o
OUTPUT = $(INPUT).ovl

ifeq ($(shell type mips64-gcc >/dev/null 2>/dev/null; echo $$?), 0)
	CROSS := mips64-
else ifeq ($(shell type mips-linux-gnu-gcc >/dev/null 2>/dev/null; echo $$?), 0)
	CROSS := mips-linux-gnu-
else
	CROSS := mips64-elf-
endif

# Binary Utilitiies
OBJCOPY = $(CROSS)objcopy
OBJDUMP = $(CROSS)objdump
CC   = @$(CROSS)gcc
LD   = $(CROSS)ld
NOVL = nOVL

CFLAGS = -I$(LIBZ64_PATH) -I$(LIBZ64_PATH)/libultra -D_LANGUAGE_C -DF3DEX_GBI_2 -D_MLDEBUG -G 0 -g -O0	\
-std=gnu99 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3							\
-mno-shared -mdivide-breaks -mno-explicit-relocs -mno-memcpy					\
-mno-check-zero-division -ffreestanding -fno-reorder-blocks

LDFLAGS = -L$(LIBZ64_PATH) -T libzelda64.ld --emit-relocs
NOVLFLAGS = -s -c -A $(SEGMENT) -o $(OUTPUT)

default: make_dir entry $(INPUT).ovl move

make_dir:
	@rm -rf $(DIST_DIR)
	@rm -rf $(BUILD_DIR)
	@mkdir $(DIST_DIR)
	@mkdir $(BUILD_DIR)

$(INPUT).ovl: $(PARTS)
	@$(LD) -o $(INPUT).elf $(PARTS) $(LDFLAGS)
	@$(NOVL) $(NOVLFLAGS) $(INPUT).elf
	@echo "Generated $(INPUT).elf"
	@echo "Compiling..."

# Create `entry.ld`
entry:
	@echo -n "ENTRY_POINT = "$(SEGMENT) > entry.ld
	@echo ";" >> entry.ld

move:
	@mv $(INPUT).elf $(BUILD_DIR)/$(INPUT).elf
	@mv $(INPUT).o $(BUILD_DIR)/$(INPUT).elf
	@mv entry.ld $(BUILD_DIR)/entry.ld
	@mv $(OUTPUT) $(DIST_DIR)/$(OUTPUT)
	@echo "Finished!"

# Remove compilation parts and some cleanup.
clean:
	rm -rf $(DIST_DIR) $(BUILD_DIR)