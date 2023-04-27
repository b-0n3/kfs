section .asm

global insb
global insw
global outb
global outw
insb:
   push ebp ; save ebp on the stack
   mov ebp, esp; ebp = esp make ebp point to the top of the stack
   xor eax, eax; eax = 0
   mov edx, [ ebp+8 ] ; edx = address of the port
   in al , dx; read a byte from port dx into al
   pop ebp; restore ebp
   ret

insw:
   push ebp ; save ebp on the stack
   mov ebp, esp; ebp = esp make ebp point to the top of the stack
   xor eax, eax; eax = 0
   in ax , dx ; read a word from port dx into ax
   pop ebp
   ret

outb:
   push ebp
   mov ebp, esp
   xor eax, eax
   mov edx, [ ebp+8 ]; edx = address of the port
   mov al, [ ebp+12 ]; al = value to
   out dx, al
   pop ebp
   ret

outw:
   push ebp
   mov ebp, esp
   xor eax, eax
   mov edx, [ ebp+8 ]; edx = address of the port
   mov ax, [ ebp+12 ]; ax = value to
   out dx, ax
   pop ebp
   ret
