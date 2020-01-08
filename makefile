CC = clang
CFLAGS = -Wall -O3 -g -I inc

main: src/main.c
	@mkdir -p bin
	@$(CC) src/main.c src/linked_list.c -o bin/main $(CFLAGS)

clean:
	@rm -rf bin

run:
	./bin/main

check: 
	valgrind ./bin/main
