INCLUDE entry.ld

OUTPUT_ARCH(mips)
OUTPUT_FORMAT("elf32-bigmips")

EXTERN(ENTRY_POINT)
ENTRY(ENTRY_POINT)

SECTIONS {
	/* Program run addressed defined in `entry.ld` */
	. = ENTRY_POINT;

	.text : ALIGN(16) SUBALIGN(8) {
		__text_start = .;
		*(.text);
		*(.text.*);
		__text_end = .;
	}
	__text_size = SIZEOF(.text);

	.rodata : ALIGN(16) SUBALIGN(4) {
		__rodata_start = .;
		*(.rodata);
		*(.rodata.*);
		__rodata_end = .;
	}
	__rodata_size = SIZEOF(.rodata);

    .data : ALIGN(16) SUBALIGN(4) {
		__data_start = .;
		*(.data);
		*(.data.*);
		__data_end = .;
	}
	__data_size = SIZEOF(.data);

    .bss : ALIGN(16) SUBALIGN(4) {
		__bss_start = . ;
		*(COMMON);
        *(.scommon);
		*(.scommon.*);
        *(.sdata);
        *(.sdata.*);
        *(.bss);
		*(.bss.*);
		__bss_end = . ;
	}
	__bss_size = SIZEOF(.bss);

	/DISCARD/ : {
      *(*);
    }

	. = ALIGN(16);
	end = . ;
}


