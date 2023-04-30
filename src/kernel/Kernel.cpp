void printDescriptorTable();

/**
 *
 * {@Author: b-0n3}
 */

#define WIDTH 80
#define HEIGHT 25


void clearScreen()
{
    for (int i = 0; i < 80 * 25; i++) {
        char *video = (char *) 0xb8000;
        video[i * 2] = ' ';
        video[i * 2 + 1] = 0x07;
    }
}

void put_char(char c)
{
    static int row;
    static int col;
    auto *video = ( unsigned char *) 0xb8000;
    if (c == '\n') {
        row++;
        col = 0;
    } else {
        video[(row * WIDTH + col) * 2] = c;
        video[(row * WIDTH + col) * 2 + 1] = 0x07;
        col++;
    }
    if (row > HEIGHT) {
        row = 0;
        col = 0;
    }

}

void print (const char *msg)
{
    for (int i = 0; msg[i] != '\0'; i++) {
        put_char(msg[i]);
    }
}


/**
 *  @Description:  the main function of the kernel
 *   this function is called by the bootloader
 *     we are making this function extern "C" to make sure that the name of the function is not mangled
 *     the name of the function is important because the bootloader is looking for a function called "main"
 *   @param void
 *   @return
  */


extern  "C" int  main() {
    clearScreen();
#ifdef KFS_1
    print("42\n");
#else
    print("Hello World");
#endif

    return 0;
}

