CFLAGS = -g -std=c99 -Wall -Wextra -pedantic -I. -I/usr/local/include 
LDFLAGS = -L/usr/local/lib

build: clean main

main: main.o mindswap.o awkmenu.o
	gcc $^ -o $@ $(LDFLAGS)

main.o: main.c
	gcc $(CFLAGS) -c $< -o $@

mindswap.o: src/mindswap.c
	gcc $(CFLAGS) -c $< -o $@

awkmenu.o: src/awkmenu.c
	gcc ${CFLAGS} -c $< -o $@

run: main
	./main

debug: clean main
	gdb --tui ./main

clean:
	echo `clear`
	rm -f main *.o 
	rm -rf ./swaps

_clean:
	echo `clear`
	rm -f main *.o 

all: clean build run
