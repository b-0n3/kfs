NAME=b-os.iso
SRC=$(shell find ./src --name '*.c')
SRC+=$(shell find ./src --name '*.s')
OBJ=$(SRC:.c=.o)

all: $(NAME)


clean:
	rm -f $(OBJ)
	rm -f $(NAME)


re: clean all