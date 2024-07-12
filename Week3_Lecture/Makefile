CFILES = $(wildcard *.c)
OFILES = $(CFILES: .c=.o)

GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles
LDFLAGS = -nostdlib -nostartfiles

all: kernel8.img run

boot.o: boot.S
	aarch64-none-elf-gcc $(GCCFLAGS) -c boot.S -o boot.o 

%.o: %.c 
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@
main.o: main.c

Uart.o: Uart.c

kernel8.img: boot.o $(OFILES)
	aarch64-none-elf-ld $ (LDFLAGS) boot.o $(OFILES) -T link.ld -o kernel8.elf
	aarch64-none-elf-objcopy -O binary kernel.elf kernel8.img
run:
	qemu-system-aarch64 -M raspib3 -kernel kernel8.img -d in_asm