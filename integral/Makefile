.PHONY: build
build:
	gcc -Wall -lm -c ./src/*.c
	gcc -Wall -lm -o main *.o

.PHONY: run
run:
	gcc -Wall -lm -c ./src/*.c
	gcc -Wall -lm -o main *.o
	main

.PHONY: clean
clean:
	rm -rf *.o ./build

.DEFAULT_GOAL := build
