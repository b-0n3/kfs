NAME=b-os

GCC_FLAGS= -fno-builtin -fno-exceptions \
			-fno-stack-protector -fno-stack-protector \
			-O0 -fno-rtti -nostdlib -nodefaultlibs \
			-nostartfiles -m32 -march=i386
CC=${TARGET}-gcc
CXX=${TARGET}-g++
LD=${TARGET}-ld
OBJCOPY=${TARGET}-objcopy

BOOT=src/boot/boot.asm
SRC=src/kernel/Kernel.cpp

$(NAME) :
	nasm -f elf32 $(BOOT) -o boot.o
	$(CXX) $(GCC_FLAGS) -c $(SRC) -o kernel.o
	$(LD) -T linker.ld -m elf_i386 boot.o kernel.o -o $(NAME)


ISO: $(NAME)
	mkdir -p iso/boot/grub
	cp $(NAME) iso/boot/
	cp src/boot/grub/grub.cfg iso/boot/grub/
	grub-mkrescue -o $(NAME).iso iso

re: clean all


run: ISO
	qemu-system-i386 --cdrom $(NAME).iso