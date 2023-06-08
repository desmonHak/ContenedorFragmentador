CC=gcc
FLAGS=-Wall -Werror -Wpedantic -x c  -time  -save-temps -g
OUTPUT=output.exe
NASM=nasm
FLAGS_NASM=-f elf64

init:
	@cls

	$(CC) main.c  $(FLAGS) -o $(OUTPUT)