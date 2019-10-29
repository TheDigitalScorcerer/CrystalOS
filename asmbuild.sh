#!/bin/bash

##nasm -f bin -o boot_sect.bin boot.asm

#gcc -ffreestanding -c kernel.c -o kernel.o
#nasm boot.asm -f elf -o boot.o

#ld -o kernel.bin -Ttext 0x1000 boot.o kernel.o --oformat binary

#dd status=noxfer conv=notrunc if=kernel.bin of=kernel.flp

make clean
make all

qemu-system-i386 -fda kernel.flp