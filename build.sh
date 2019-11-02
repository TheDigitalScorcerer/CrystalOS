#!/bin/bash
make clean
make all
qemu-system-i386 -cdrom kernel.iso -no-reboot -no-shutdown -monitor stdio