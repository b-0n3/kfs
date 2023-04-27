TARGET=b-os.iso
BUILD_DIR=./build
BIN_DIR=./bin
KERNEL=bin/kernel.bin
KERNEL_DIR=src/kernel
ISO_DIR=./iso

all: $(TARGET)


$(TARGET): $(KERNEL)
	if [ ! -d $(ISO_DIR) ]; then mkdir -p $(ISO_DIR)/boot/grub; fi
	cp $(KERNEL) $(ISO_DIR)/boot/b-os.bin
	cp $(KERNEL_DIR)/boot/grub/* $(ISO_DIR)/boot/grub/
	grub-mkrescue -o $(TARGET) $(ISO_DIR)

$(KERNEL): 
	make re  -C $(KERNEL_DIR)

clean: 
	make clean -C $(KERNEL_DIR)

fclean: clean
	rm -rf $(KERNEL)
	rm -rf $(TARGET)
	rm -rf $(ISO_DIR)

re: fclean all
