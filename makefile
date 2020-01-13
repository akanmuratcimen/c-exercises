CC = clang
CFLAGS = -W -Wall -Werror -I inc -std=c11 -g -pedantic -lm
SRCFILES = $(wildcard src/*.c)
OUTPUT = bin/main

main: src/main.c
	@mkdir -p bin
	@$(CC) $(SRCFILES) -o $(OUTPUT) $(CFLAGS)

clean:
	@rm -rf bin asm

run:
	./$(OUTPUT)

check:
	valgrind ./$(OUTPUT)

asm:
	@$(CC) $(SRCFILES) -S -mllvm --x86-asm-syntax=intel -g $(CFLAGS)
	@mkdir -p asm
	@mv *.s asm

.PHONY: asm
