PROGRAM = puppet
OVLOUT = puppet.ovl
ADDRESS = 0x80800000
OBJDUMP = mips64-objdump
PARTS = $(PROGRAM).o

ifeq ($(shell type mips64-gcc >/dev/null 2>/dev/null; echo $$?), 0)
	CROSS := mips64-
else ifeq ($(shell type mips-linux-gnu-gcc >/dev/null 2>/dev/null; echo $$?), 0)
	CROSS := mips-linux-gnu-
else
	CROSS := mips64-elf-
endif

CC   = $(CROSS)gcc
LD   = $(CROSS)ld
NOVL = nOVL

CFLAGS = -I$(LIBZ64_PATH) -I$(LIBZ64_PATH)/libultra -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI_2 -D_MLDEBUG -DGAME_MM -DGAME_VERSION_1_0 -G 0 -Ofast	\
-std=gnu11 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3							\
-mno-shared -mdivide-breaks -mno-explicit-relocs -mno-memcpy					\
-mno-check-zero-division -ffreestanding -fno-reorder-blocks -w

LDFLAGS = -L$(LIBZ64_PATH) -T libzelda64.ld --emit-relocs
NOVLFLAGS = -s -c -A $(ADDRESS) -o $(OVLOUT)

default: clean entry $(PROGRAM).ovl sync move

$(PROGRAM).ovl: $(PARTS)
	@$(LD) -o $(PROGRAM).elf $(PARTS) $(LDFLAGS)
	@$(NOVL) $(NOVLFLAGS) $(PROGRAM).elf
	@echo "Generated $(PROGRAM).elf"
	@echo "Compiling..."
	@mv $(OVLOUT) bin/$(OVLOUT)
	@echo bin/$(OVLOUT) written successfully!
	@rm *.elf *.ld

entry:
	@echo -n "ENTRY_POINT = "$(ADDRESS) > entry.ld
	@echo ";" >> entry.ld
	@echo "Generated entry.ld"

symbols:
	@$(OBJDUMP) -t $(PROGRAM).elf > symbols.txt

sync:
	@echo Generating Instance Sync Data...
	@$(MAKE) -s -C puppet_sync
	@mv PuppetData.json bin/PuppetData.json
	@echo bin/PuppetData.ts written successfully!

move:
	@echo Moving to payload folder...
	@cp bin/$(OVLOUT) /mnt/c/ModLoader64/OcarinaOfTimeOnline/src/OotOnline/payloads/E0/$(OVLOUT)
	@echo Moved $(OVLOUT)!
	@cp bin/PuppetData.json /mnt/c/ModLoader64/OcarinaOfTimeOnline/src/OotOnline/data/linkPuppet/PuppetData.json
	@echo Moved PuppetData.json!

clean:
	@rm -f $(PROGRAM).elf $(OVLOUT) $(PARTS) *.o entry.ld

