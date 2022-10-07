all: main

.PHONY: main
main: main.c bloom.c bits.c
	gcc -Wall -Wextra -o $@ $^