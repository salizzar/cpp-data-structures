NAME := cpp-data-structures
CC := g++
DBG := gdb

clean:
	rm -rf bin; mkdir bin;

build: clean
	$(CC) -I include src/** -o bin/$(NAME)

debug: clean
	$(CC) -I include -g src/** -o bin/$(NAME)-test
	$(DBG) bin/$(NAME)-test

all: build

