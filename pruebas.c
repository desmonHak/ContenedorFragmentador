// clear;nasm -f elf64 pruebas.asm;gcc pruebas.c pruebas.o -o pruebas.bin

extern char _func();
#include <stdio.h>

#include "includes/stack.h"

unsigned char __attribute__((section(".mySection"))) buf[12] = "ssasd";
unsigned char __attribute__((section(".mySection"))) myOtherVar = 0xff;
unsigned char __attribute__((section(".text")))
myOtherVa1r[] = {0x01, 0x02, 0x03, 0x04};

int main()
{
	for (int i = sizeof(myOtherVa1r); i < 0xff; i++)
	{
		printf("%x ", *(myOtherVa1r + i + 12));
	}
	printf("\n %2.x\n", myOtherVa1r);
	printf("%d\n", _func());


	var MiCelda = new(1, _ui16, 2);

	return 0;
}