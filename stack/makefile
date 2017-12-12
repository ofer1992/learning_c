CC=gcc
CCFLAGS=-Wall -std=c99 -Wvla

all: main.o stack.o
	$(CC) $(CCFLAGS) $? -o prog 
	
%.o: %.c stack.h
	$(CC) $(CCFLAGS) -c $< -o $@
	
clean:
	-rm -f *.o prog
.PHONY : clean
