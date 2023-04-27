bits 32

section .multiboot   ;according to multiboot spec
align 4
        ; This is the GRUB Multiboot header. A boot signature
        dd 0x1BADB002
        dd 1<<0 | 1<<1
        dd -(0x1BADB002 + (1<<0 | 1<<1))



section .text

global start
extern main                      ;defined in the C file

start:
        cli                      ;block interrupts
        mov esp, stack_space     ;set stack pointer
        call main
        hlt                      ;halt the CPU

section .bss
resb 16000                        ;16KB for stack
stack_space: