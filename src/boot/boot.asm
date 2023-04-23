mov ah , 0x0e
mov al, 'a'
loop:
  inc al
  int 0x10
  cmp al, 'z'
  je done
  jmp loop
done:
  nop
times 510-($-$$) db 0

db 0x55, 0xaa
