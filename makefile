C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)

OBJ = ${C_SOURCES:.c=.o}

#all: kernel.flp
all: kernel.iso

#run: all

kernel.iso: kernel.bin
	grub-file --is-x86-multiboot $^

	#building the iso file
	mkdir -p isodir/boot/grub
	cp $^ isodir/boot/$^
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir

kernel.bin: boot.o ${OBJ}
	ld -m elf_i386 -T linker.ld $^ -o $@ -nostdlib

#kernel.flp: boot/boot_sect.bin #kernel.bin#kernel/kernel_entry.bin
#	cat $^ > os-image
#	dd status=noxfer conv=notrunc if=os-image of=kernel.flp

#kernel.bin: kernel/kernel_entry.o ${OBJ}
#	#ld -m elf_i386 -T kernel/link.ld -o $@ $^
#	ld -o $@ -Ttext 0x1000 $^ --oformat binary -melf_i386
#	#ld -o $@ -Ttext 0x1000 $^ --oformat binary -O elf32-i386

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