#@copyright : Mina Fathy

CC=arm-none-eabi-
CFLAGS=-mthumb -mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=

#all .c files are saved in SRC
SRC= $(wildcard *.c) 
#all .c files in SRC , rename them to .o and save in OBJ
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=Lab-3-cortex-M4

#runing board variables
PROC=arm
M_type=versatilepb
Mem_size=128M
RFLAGS=-nographic


all: $(Project_name).bin
	@echo "==============Build done=============="

#startup.o: startup.s	
#$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=Mapfile.map $(LIBS) $(OBJ) $(AsOBJ) -o $@
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin : $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

run:
	qemu-system-$(PROC) -M $(M_type) -m $(Mem_size) $(RFLAGS) -kernel $(Project_name).bin


clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin