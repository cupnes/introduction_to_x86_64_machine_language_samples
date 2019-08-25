TARGET = kernel.bin
CFLAGS = -Wall -Wextra -nostdinc -nostdlib -fno-builtin -fno-common
LDFLAGS = -Map kernel.map -s -x -T kernel.ld
OBJS = loop.o

$(TARGET): $(OBJS)
	ld $(LDFLAGS) -o $@ $+

%.o: %.s
	gcc $(CFLAGS) -c -o $@ $<
%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	cp $< ../fs/
	../run.sh ../fs

disassemble: $(TARGET)
	dd if=$(TARGET) of=$(TARGET).text bs=1 skip=16
	objdump -D -b binary -m i386:x86-64 $(TARGET).text
	rm $(TARGET).text

clean:
	rm -f *~ *.o *.map $(TARGET) $(TARGET).text

.PHONY: run clean
