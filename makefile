CC = clang
CFLAGS = -Wall -O3 -g -I.

main: src/main.c
	@mkdir -p bin
	$(CC) src/main.c -o bin/main $(CFLAGS)

clean:
	rm -rf bin

run: 
	./bin/main

.PHONY: main