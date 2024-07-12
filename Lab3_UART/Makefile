#--------------------------------------Makefile------------------------------------- 
 
CFILES = $(wildcard *.c) 
OFILES = $(CFILES:.c=.o) 
CCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles 
 
all: kernel8.img 
 
boot.o: boot.S 
	aarch64-none-elf-gcc $(CCFLAGS) -c boot.S -o boot.o 
 
%.o: %.c 
	aarch64-none-elf-gcc $(CCFLAGS) -c $< -o $@ 
 
kernel8.img: boot.o $(OFILES) 
	aarch64-none-elf-ld -nostdlib -nostartfiles boot.o $(OFILES) -T link.ld -o kernel8.elf 
	aarch64-none-elf-objcopy -O binary kernel8.elf kernel8.img 

run: 
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -serial null -serial stdio