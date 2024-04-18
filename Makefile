CFLAGS = -g -std=c99 -Wall -Wextra -pedantic -I. -I/usr/local/include 

LDFLAGS = -g -L/usr/local/include

build: clean
	gcc $(CFLAGS) $(LDFLAGS) main.c -o main.o 

run:
	./main.o

debug: 
	rm -rf ./main.o
	clang $(CFLAGS) $(LDFLAGS) main.c -o main.o 
	echo `clear`
	gdb --tui -ex 'set logging file ./gdb.txt' -ex 'set logging overwrite on' ./main.o

clean:
	echo `clear`
	rm -rf ./main.o

all: clean build run
		
	