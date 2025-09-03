TARGET = Onizone
BUILD = build
SOURCES = src
INCLUDES = include

ARCH := -mthumb -mthumb-interwork

CFLAGS := -O2 -Wall $(ARCH) -I$(INCLUDES)
LDFLAGS := -specs=gba.specs

OBJS := $(SOURCES)/main.o $(SOURCES)/battle.o $(SOURCES)/npc.o

$(TARGET).gba : $(OBJS)
	arm-none-eabi-gcc $(ARCH) -o $(TARGET).elf $(OBJS) $(LDFLAGS)
	arm-none-eabi-objcopy -O binary $(TARGET).elf $(TARGET).gba

%.o : %.c
	arm-none-eabi-gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SOURCES)/*.o *.elf *.gba
