OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
{
   . = 1M; /* start at 1MB */
     .text BLOCK(4K) : ALIGN(4K) /* 4K alignment */
     {
         *(.multiboot) /* multiboot header */
         *(.text)     /* code */
     }
     .data : { *(.data) } /* data */
     .bss  : { *(.bss)  } /* bss */
     .asm :   /* make sure the .asm section is last */
        {
            *(.asm)
        }
}
