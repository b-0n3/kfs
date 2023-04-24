//
// Created by b1 on 4/24/23.
//


/**
 *  @Description:  print a string on the screen
 *   the string is print in the first line of the screen
 *
 *   @param str: the string to print
 *   @return: void
 *
 *
  */
void print(const char* str)
{
    // the video memory starts at 0xb8000
    // each character is 2 bytes
    // the first byte is the ASCII code of the character
    // the second byte is the color of the character
    // the color is a combination of 4 bits for the background and 4 bits for the foreground
    static unsigned short* VideoMemory = (unsigned short*)0xb8000; // address of the first character in the video memory

    for (int i = 0; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

/**
 *  @Description:  the main function of the kernel
 *   this function is called by the bootloader
 *     we are making this function extern "C" to make sure that the name of the function is not mangled
 *     the name of the function is important because the bootloader is looking for a function called "main"
 *   @param void
 *   @return: void
 *
 *
  */
extern  "C" int main() {
    print("Hello, World!");
    return 0;
}