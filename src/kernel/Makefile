TARGET=$(BIN_DIR)/kernel.bin
SRCS= $(shell find . -name "*.cpp")
ASM_FILES= $(shell find . -name "*.asm" | grep -v "boot.asm")

# delete the ./ from the all SRCS
SRCS:= $(subst ./,,$(SRCS))
ASM_FILES:= $(subst ./,,$(ASM_FILES))

BOOT= boot/boot.asm
# check if BIN_DIR  and BUILD_DIR are define and set them to default value if not
ifndef BIN_DIR
	BIN_DIR=$(PWD)/bin
endif

ifndef BUILD_DIR
	BUILD_DIR=$(PWD)/out
endif

OBJ=$(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))
OBJ+=$(addprefix $(BUILD_DIR)/,$(ASM_FILES:.asm=.o))
BOOT_BIN=$(BUILD_DIR)/boot.o

INCLUDES= ./
CPPFLAGS=  -I$(INCLUDES)

CPPFLAGS +=  -fno-builtin -fno-exceptions \
			-fno-stack-protector -fno-stack-protector \
			-O0 -fno-rtti -nostdlib -nodefaultlibs \
			-nostartfiles -m32 -march=i386

ifeq ($(DEBUG),1)
	FLAGS+= -g
endif
ifeq ($(GDB),1)
	FLAGS+= -DDEBUG -DGDB
endif
ifeq ($(KFS_1),1)
	FLAGS+= -DKFS_1=1
endif


# make sure that the build and bin directory exist
$(shell mkdir -p $(BUILD_DIR))
$(shell mkdir -p $(BIN_DIR))

$(BUILD_DIR)/%.o: %.cpp
	if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CXX) $(CPPFLAGS)  -c  $? -o $@

$(BUILD_DIR)/%.o: %.asm
	if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	nasm   -f elf32 $? -o $@

all: $(TARGET)


$(TARGET): $(BOOT_BIN) $(OBJ)
	$(LD) -T linker.ld $(BOOT_BIN) $(OBJ) -o $(TARGET)

$(BOOT_BIN) : $(BOOT)
	nasm  $(BOOT) -o $(BOOT_BIN)

clean: 
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(TARGET)

re: fclean all
