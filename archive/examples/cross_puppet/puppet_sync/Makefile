ADDRESS = 0x0

CC   = @mips64-gcc
LD   = mips64-ld
OBJCOPY = mips64-objcopy
OBJDUMP = mips64-objdump

CFLAGS = -I$(LIBZ64_PATH) -I$(LIBZ64_PATH)/libultra -I../include -I../src -G 0 -O0 						\
-D_LANGUAGE_C -DF3DEX_GBI_2 -D_MLDEBUG \
--std=gnu99 -mtune=vr4300 -mabi=32 -mips3 			\
-mno-explicit-relocs -mno-memcpy -ffreestanding		\
-Wno-main -mno-gpopt -Wno-unused-function 			\
-fomit-frame-pointer -mno-check-zero-division

LDFLAGS = -L$(LIBZ64_PATH) -T libzelda64.ld --emit-relocs
NOVLFLAGS = -s -c -A $(ADDRESS) -o $(OVLOUT)

OOT_FLAGS = -DGAME_OOT -DGAME_VERSION_1_0
MM_FLAGS = -DGAME_MM -DGAME_VERSION_1_0

default: clean sync_data

sync_data:
	@echo "Generating PuppetData..."
	@echo -n "ENTRY_POINT = " > entry.ld
	@echo -n $(ADDRESS) >> entry.ld
	@echo -n ";" >> entry.ld
	@$(CC) -c sync.c $(CFLAGS) $(OOT_FLAGS)
	@$(LD) -o sync.elf sync.o $(LDFLAGS) $(LDFILE)
	@$(OBJCOPY) -R .MIPS.abiflags -O binary sync.elf sync.bin
	@echo -n "data_start=0x" > sync_sym.txt
	@$(OBJDUMP) -t sync.elf | grep "sync_entries" | cut -c1-8 >> sync_sym.txt
	@echo -n "ivars=0x" >> sync_sym.txt
	@$(OBJDUMP) -t sync.elf | grep "initVars" | cut -c1-8 >> sync_sym.txt
	@node makeData/makets.js
	@echo "Congratualtions! This was a massive pain in the <redacted>!"
	cp ../PuppetData.json ../bin/PuppetSync_OOT.json
	@rm -f *.bin *.elf *.o *.ld *.txt
	@echo "Generating PuppetData..."
	@echo -n "ENTRY_POINT = " > entry.ld
	@echo -n $(ADDRESS) >> entry.ld
	@echo -n ";" >> entry.ld
	@$(CC) -c sync.c $(CFLAGS) $(MM_FLAGS)
	@$(LD) -o sync.elf sync.o $(LDFLAGS) $(LDFILE)
	@$(OBJCOPY) -R .MIPS.abiflags -O binary sync.elf sync.bin
	@echo -n "data_start=0x" > sync_sym.txt
	@$(OBJDUMP) -t sync.elf | grep "sync_entries" | cut -c1-8 >> sync_sym.txt
	@echo -n "ivars=0x" >> sync_sym.txt
	@$(OBJDUMP) -t sync.elf | grep "initVars" | cut -c1-8 >> sync_sym.txt
	@node makeData/makets.js
	@echo "Congratualtions! This was a massive pain in the <redacted>!"
	cp ../PuppetData.json ../bin/PuppetSync_MM.json
	@rm -f *.bin *.elf *.o *.ld *.txt

clean:
	@rm -f *.bin *.elf *.o *.ld