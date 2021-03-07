@echo off
set PATH=%PATH%;%cd%/gcc/bin;%cd%/nOVL
set LIBZ64_PATH=%cd%/gcc/mips64/include/
set LIBZ64_LD=libzelda64.ld
set ADDRESS=0x80800000

echo COMPILING
mips64-gcc -I%LIBZ64_PATH% -G 0 -Ofast --std=gnu99 -mtune=vr4300 -march=vr4300 -mabi=32 -mips3 -mno-shared -mdivide-breaks -mno-explicit-relocs -mno-memcpy -mno-check-zero-division -ffreestanding -fno-reorder-blocks %1.c -o %1.o

echo LINKING
mips64-ld -o %1.elf %1.o -L%LIBZ64_PATH% -T %LIBZ64_LD% --emit-relocs

echo NOVLING
nOvl -s -c -A %ADDRESS% -o %1.ovl

echo OBJDUMPING
mips64-objdump -t %1.elf > symbols.txt

echo DONE!

pause

