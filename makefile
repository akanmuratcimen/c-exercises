CC = clang
CFLAGS = -Wall -g -I inc

main: src/main.c
	@mkdir -p bin
	$(CC) src/main.c src/linked_list.c -o bin/main $(CFLAGS)

clean:
	rm -rf bin

run: 
	./bin/main

.PHONY: main