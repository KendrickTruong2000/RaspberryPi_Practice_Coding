#--------------------------------------Makefile------------------------------------- 
 
CFILES = $(wildcard *.c) 
OFILES = $(CFILES:.c=.o) 
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles 
 
all: kernel8.img 
 
boot.o: boot.S 
	aarch64-none-elf-gcc $(GCCFLAGS) -c boot.S -o boot.o 
 
%.o: %.c 
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@ 
 
kernel8.img: boot.o $(OFILES) 
	aarch64-none-elf-ld -nostdlib -nostartfiles boot.o $(OFILES) -T link.ld -o kernel8.elf 
	aarch64-none-elf-objcopy -O binary kernel8.elf kernel8.img 