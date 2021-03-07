PROGRAM = puppet
OVLOUT = puppet.ovl
ADDRESS = 0x80800000
OBJDUMP = mips64-objdump
PARTS = $(PROGRAM).o

CC   = @mips64-gcc
LD   = mips64-ld
NOVL = nOVL

CFLAGS = -I$(LIBZ64_PATH) -D_MLDEBUG -G 0 -g -O0							\
-std=gnu99 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3			\
-mno-shared -mdivide-breaks -mno-explicit-relocs -mno-memcpy	\
-mno-check-zero-division -ffreestanding -fno-reorder-blocks

LDFLAGS = -L$(LIBZ64_PATH) -T $(LIBZ64_LD) --emit-relocs
NOVLFLAGS = -s -c -A $(ADDRESS) -o $(OVLOUT)

default: entry $(PROGRAM).ovl symbols

$(PROGRAM).ovl: $(PARTS)
	@$(LD) -o $(PROGRAM).elf $(PARTS) $(LDFLAGS)
	@$(NOVL) $(NOVLFLAGS) $(PROGRAM).elf
	@echo "Generated $(PROGRAM).elf"
	@echo "Compiling..."

entry:
	@echo -n "ENTRY_POINT = "$(ADDRESS) > entry.ld
	@echo ";" >> entry.ld
	@echo "Generated entry.ld"

symbols:
	@$(OBJDUMP) -t $(PROGRAM).elf > symbols.txt

# You can add this to defualt to automatically run `make` on /puppet_sync/Makefile
# However, keep in mind that the .NET Framework is probably necessary for `makets`
# to execute properly. Everything should still work fine if you run the subdirectories
# makefile like normal at your leisure.
gen_sync:
	@$(MAKE) -s -C puppet_sync

clean:
	@rm -f $(PROGRAM).elf $(OVLOUT) $(PARTS) entry.ld

