CC=gcc
CFLAGS= -Wall -Wextra -std=c99

build: make.o func.o
	$(CC) $(CFLAGS) make.o func.o -o hello

clean:
	rm *.o
.PHONY : clean
