OUTPUT_FORMAT(elf32-i386)
ENTRY(start)

PHDRS {
    code PT_LOAD;
    data PT_LOAD;
}

SECTIONS {
    . = 1M;
    .text : {
        *(.multiboot)
        *(.text)
    } :code
    .data : {
        *(.data)
    } :data
    .bss : {
        *(.bss)
    } :data
    /DISCARD/ : { *(.comment) }
}