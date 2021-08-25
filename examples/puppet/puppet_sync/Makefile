ADDRESS = 0x0

CC   = @mips64-gcc
LD   = mips64-ld
OBJCOPY = mips64-objcopy
OBJDUMP = mips64-objdump

CFLAGS = -I$(LIBZ64_PATH) -I$(LIBZ64_PATH)/libultra -G 0 -Os 						\
--std=gnu99 -mtune=vr4300 -mabi=32 -mips3 			\
-mno-explicit-relocs -mno-memcpy -ffreestanding		\
-Wno-main -mno-gpopt -Wno-unused-function 			\
-fomit-frame-pointer -mno-check-zero-division

LDFLAGS = -L$(LIBZ64_PATH) -T libzelda64.ld --emit-relocs
NOVLFLAGS = -s -c -A $(ADDRESS) -o $(OVLOUT)

default: clean sync_data

sync_data:
	@echo "Generating PuppetData..."
	@echo -n "ENTRY_POINT = " > entry.ld
	@echo -n $(ADDRESS) >> entry.ld
	@echo -n ";" >> entry.ld
	@$(CC) -c sync.c $(CFLAGS)
	@$(LD) -o sync.elf sync.o $(LDFLAGS) $(LDFILE)
	@$(OBJCOPY) -R .MIPS.abiflags -O binary sync.elf sync.bin
	@echo -n "data_start=0x" > sync_sym.txt
	@$(OBJDUMP) -t sync.elf | grep "sync_entries" | cut -c1-8 >> sync_sym.txt
	@echo -n "ivars=0x" >> sync_sym.txt
	@$(OBJDUMP) -t sync.elf | grep "initVars" | cut -c1-8 >> sync_sym.txt
	@node makeData/makets.js
	@echo "Congratualtions! This was a massive pain in the <redacted>!"
	@rm -f *.bin *.elf *.o *.ld *.txt

clean:
	@rm -f *.bin *.elf *.o *.ld