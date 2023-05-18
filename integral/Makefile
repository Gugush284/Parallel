.PHONY: build
build:
	gcc -Wall -lm -c ./src/*.c
	mkdir -p ./build
	gcc -Wall -lm -o ./build/task *.o

.PHONY: clean
clean:
	rm -rf *.o ./build

.DEFAULT_GOAL := build
