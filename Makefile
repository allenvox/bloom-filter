all: main

.PHONY: main
main: main.c bloom.c
	gcc -Wall -Wextra -o $@ $^