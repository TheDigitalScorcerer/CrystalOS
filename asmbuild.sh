nasm -f bin -o kernel.bin boot.asm
dd status=noxfer conv=notrunc if=kernel.bin of=kernel.flp