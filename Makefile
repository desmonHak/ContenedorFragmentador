CC=gcc
FLAGS=-Wall
OUTPUT=output.bin
NASM=nasm
FLAGS_NASM=-f elf64

init:
	@clear
	$(NASM) $(FLAGS_NASM) pruebas.asm 
	$(CC) pruebas.o main.c  $(FLAGS) -o $(OUTPUT)