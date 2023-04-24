
##  build a cross-compiler
``
@see https://wiki.osdev.org/GCC_Cross-Compiler
``

```bash
    export PREFIX="$HOME/opt/cross"
    # use i386 architecture
    export TARGET=i386-elf
    export PATH="$PREFIX/bin:$PATH"
    
```


## build the kernel 
```bash
    ./build.sh
```


##  create iso

```bash
    mkdir iso
    mkdir iso/boot
    mkdir iso/boot/grub
    cp out/kernel.bin iso/boot/kernel.bin
    cp boot/grub/grub.cfg iso/boot/grub/grub.cfg
    grub-mkrescue -o myos.iso iso
```
