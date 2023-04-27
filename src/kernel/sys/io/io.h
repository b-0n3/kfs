//
// Created by b1 on 4/24/23.
//

#ifndef KERNEL_IO_H
#define KERNEL_IO_H

/**
 * @See https://c9x.me/x86/html/file_module_x86_id_139.html\
 * @See https://wiki.osdev.org/Serial_Ports
 */

/**
 *  read one byte from a port
 *
 * @param port
 * @return  on byte from port X
 */
unsigned char insb(unsigned  short port);
/**
 *  read two bytes from a port
 * @param port
 * @return two bytes from port x
 */
unsigned short insw(unsigned  short port)

/**
 * @param port  port to write to
 * @param val value to write to the port
 */
void outb(unsigned short port, unsigned char val);
void outw(unsigned short port, unsigned short  val);

#endif //KERNEL_IO_H
