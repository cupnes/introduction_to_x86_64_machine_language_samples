TARGET = kernel.bin
CFLAGS = -Wall -Wextra -nostdinc -nostdlib -fno-builtin -fno-common
LDFLAGS = -Map kernel.map -s -x -T kernel.ld

$(TARGET): main.o
	ld $(LDFLAGS) -o $@ $+

%.o: %.s
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f *~ *.o *.map $(TARGET)

.PHONY: run clean
