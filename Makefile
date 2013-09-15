NAME := cpp-data-structures

clean:
	rm -rf bin; mkdir bin;

build: clean
	g++ -I include src/** -o bin/$(NAME)

debug: clean
	g++ -I include -g src/** -o bin/$(NAME)-test
	gdb bin/$(NAME)-test

all: build

