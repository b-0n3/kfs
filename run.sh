#!/bin/bash

ISO=b-os.iso

# if iso does not exist, build it

if [ ! -f $ISO ]; then
    ./build.sh
fi

# run the iso in qemu
qemu-system-i386 -cdrom $ISO