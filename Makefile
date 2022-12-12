all: main

.PHONY: main
main: main.c bloom.c bits.c hashtab.c
	gcc -Wall -Wextra -g -o $@ $^

clean:
	rm -rf main *.o