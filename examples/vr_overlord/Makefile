PROGRAM = vr_overlord
OVLOUT = vr_overlord.ovl
ADDRESS = 0x80800000
OBJDUMP = mips64-objdump
PARTS = $(PROGRAM).o

CC   = @mips64-gcc
LD   = mips64-ld
NOVL = nOVL
CP   = @cp

CFLAGS = -I$(LIBZ64_PATH) -I$(LIBZ64_PATH)/libultra -D_LANGUAGE_C -DF3DEX_GBI_2 -D_MLDEBUG -G 0 -g -O0	\
-std=gnu99 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3							\
-mno-shared -mdivide-breaks -mno-explicit-relocs -mno-memcpy					\
-mno-check-zero-division -ffreestanding -fno-reorder-blocks

LDFLAGS = -L$(LIBZ64_PATH) -T libzelda64.ld --emit-relocs
NOVLFLAGS = -s -c -A $(ADDRESS) -o $(OVLOUT)

default: clean entry $(PROGRAM).ovl

$(PROGRAM).ovl: $(PARTS)
	@$(LD) -o $(PROGRAM).elf $(PARTS) $(LDFLAGS)
	@$(NOVL) $(NOVLFLAGS) $(PROGRAM).elf
	@echo "Generated $(PROGRAM).elf"
	@echo "Compiling..."
	@echo "Success!"
	@echo "Generated $(OVLOUT)"
	$(CP) $(PROGRAM).ovl "C:\Users\drahs\Documents\VsProjs\ModLoader64\Plugins\Z64FreeCam\src\Z64FreeCam\payloads\e0"

entry:
	@echo -n "ENTRY_POINT = "$(ADDRESS) > entry.ld
	@echo ";" >> entry.ld
	@echo "Generated entry.ld"

clean:
	@rm -f $(PROGRAM).elf $(OVLOUT) $(PARTS) entry.ld