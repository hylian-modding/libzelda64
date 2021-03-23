ADDRESS = 0x0

CC   = @mips64-gcc
LD   = mips64-ld
OBJCOPY = mips64-objcopy
OBJDUMP = mips64-objdump

CFLAGS = -Iinclude -G 0 -Os 						\
--std=gnu99 -mtune=vr4300 -mabi=32 -mips3 			\
-mno-explicit-relocs -mno-memcpy -ffreestanding		\
-Wno-main -mno-gpopt -Wno-unused-function 			\
-fomit-frame-pointer -mno-check-zero-division		
LDFLAGS = --emit-relocs -T										
LDFLAGS = -L$(Z64OVL_LD) -T z64ovl.ld --emit-relocs

default: clean sync_data

sync_data:
	@echo "Generating PuppetData..."
	@echo -n "ENTRY_POINT = " > entry.ld
	@echo -n $(ADDRESS) >> entry.ld
	@echo -n ";" >> entry.ld
	@$(CC) -c sync.c $(CFLAGS)
	@$(LD) -o sync.elf sync.o $(LDFLAGS) $(LDFILE)
	@$(OBJCOPY) -R .MIPS.abiflags -O binary sync.elf sync.bin
	@echo -n "data_start=0x" > d.txt
	@$(OBJDUMP) -t sync.elf | grep "l    d  .data" | cut -c1-8 >> d.txt
	@echo -n "ivars=0x" >> d.txt
	@$(OBJDUMP) -t sync.elf | grep "init_vars" | cut -c1-8 >> d.txt
	@makets/makets
	@mv PuppetData.ts ../PuppetData.ts
	@echo "Success!"
	@rm -f *.bin *.elf *.o entry.ld

clean:
	@rm -f *.bin *.elf *.o