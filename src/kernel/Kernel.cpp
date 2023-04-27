/**
 *
 * {@Author: b-0n3}
 */






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

    return 0;
}