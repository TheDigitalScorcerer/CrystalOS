C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)

OBJ = ${C_SOURCES:.c=.o}

all: kernel.iso

run: all clean

kernel.iso: crystal.bin
	grub-file --is-x86-multiboot $^

	# building the iso file
	mkdir -p isodir/boot/grub
	cp $^ isodir/boot/$^
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir

crystal.bin: boot.o ${OBJ}
	ld -m elf_i386 -T linker.ld $^ -o $@ -nostdlib

boot.o:
	as --32 boot.s -o $@

%.o : %.c ${HEADERS}
	gcc -ffreestanding -c $< -o $@ -m32 -fno-pie -Wall -Wextra
	#gcc -ffreestanding -c $< -o $@ -mbe32 -fno-pie

%.o : %.asm
	nasm $< -f elf -o $@
	#nasm $< -f elf32 -o $@

%.bin : %.asm
	nasm $< -f bin -I "boot/" -o $@

clean:
	rm -fr *.bin *.dis *.o os-image
	rm -fr kernel/*.o boot/*.bin drivers/*.o
	rm -r isodir