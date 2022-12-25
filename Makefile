CC=gcc
FLAGS=-Wall -g
OUTPUT=output.bin
NASM=nasm
FLAGS_NASM=-f elf64

init:
	@clear

	@#Esto solo fue para pruebas
	@#$(NASM) $(FLAGS_NASM) pruebas.asm 
	@#$(CC) pruebas.o main.c  $(FLAGS) -o $(OUTPUT)

	@echo "[*] Iniciando compilacion:"
	$(CC) main.c  $(FLAGS) -o $(OUTPUT)