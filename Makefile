# Makefile for Kalman filter example

TARGET = kalman_example

# Compiler and flags
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -g -std=c99
LDFLAGS = -nostartfiles -T linker_script.ld
INCLUDES = -I.

# Source files
SRCS = main.c kalman.c startup.c
OBJS = $(SRCS:.c=.o)

# Build rules
all: kalman_example.elf

kalman_example.elf: main.o afro_kalman.o startup.o
	$(CC) -mcpu=cortex-m3 -mthumb -nostartfiles -T linker_script.ld main.o afro_kalman.o startup.o -o kalman_example.elf -lm

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

startup.o: startup.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Wall -g -std=c99 -c startup.c -o startup.o

afro_kalman.o: afro_kalman.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Wall -g -std=c99 -c afro_kalman.c -o afro_kalman.o

clean:
	rm -f *.elf *.o *.bin

.PHONY: all clean

# all: $(TARGET).elf

# $(TARGET).elf: $(OBJS)
# 	$(CC) $(LDFLAGS) $(OBJS) -o $@

#%.o: %.c
#	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#clean:
#	rm -f $(OBJS) $(TARGET).elf
