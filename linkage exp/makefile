CC=gcc
CCFLAGS=-Wall

all: file1.o file2.o
	$(CC) $(CCFLAGS) $? -o prog

%.o: %.c file1.h
	$(CC) $(CCFLAGS) -c $< -o $@
	
clean:
	-rm -f *.o prog
.PHONY: clean

