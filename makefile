C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)

OBJ = ${C_SOURCES:.c=.o}

all: os-image

run: all
	bochs

os-image: boot/boot_sect.bin kernel.bin
	cat $^ > os-image
	dd status=noxfer conv=notrunc if=os-image of=kernel.flp

kernel.bin: kernel/kernel_entry.o ${OBJ}
	ld -o $@ -Ttext 0x1000 $^ --oformat binary -melf_i386

%.o : %.c ${HEADERS}
	gcc -ffreestanding -c $< -o $@ -m32 -fno-pie

%.o : %.asm
	nasm $< -f elf -o $@

%.bin : %.asm
	nasm $< -f bin -I "boot/" -o $@

clean:
	rm -fr *.bin *.dis *.o os-image
	rm -fr kernel/*.o boot/*.bin drivers/*.o