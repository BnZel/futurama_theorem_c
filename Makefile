CFLAGS = -g -std=c99 -Wall -Wextra -pedantic -I. -I./unity_test -I/usr/local/include 

LDFLAGS = -g -L/usr/local/include

UNITY_ROOT=./unity_test
TARGET_BASE=test
TARGET_EXTENSION=.o
TARGET=$(TARGET_BASE)$(TARGET_EXTENSION)
SRC_FILES=$(UNITY_ROOT)/unity.c main.c $(UNITY_ROOT)/test/Test.c


build: clean
	gcc $(CFLAGS) $(LDFLAGS) main.c -o main.o 

test: clean
	echo `clear`
	gcc $(CFLAGS) $(LDFLAGS) $(SRC_FILES) -o $(TARGET)
	./test.o

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
	rm -rf ./test.o

all: clean build run
		
	