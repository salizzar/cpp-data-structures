NAME := cpp-data-structures

clean:
	rm -rf bin; mkdir bin;

build: clean
	g++ -I include -g src/** -o bin/$(NAME)

all: build

