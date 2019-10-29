mkdir -p build/object

nasm -f elf32 kernel.asm -o build/object/kasm.o
#gcc -m32 -c kernel.c -o kc.o
gcc -fno-stack-protector -m32 -c kernel.c -o build/object/kc.o
ld -m elf_i386 -T link.ld -o kernel.bin build/object/kasm.o build/object/kc.o

grub-file --is-x86-multiboot kernel.bin

mkdir -p isodir/boot/grub
mv kernel.bin isodir/boot/kernel.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o kernel.iso isodir

rm -r build
rm -r isodir