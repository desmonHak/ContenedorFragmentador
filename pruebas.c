extern char _func();
#include <stdio.h>

unsigned char __attribute__((section(".mySection"))) buf[12] = "ssasd";
unsigned char __attribute__((section(".mySection"))) myOtherVar = 0xff;
unsigned char __attribute__((section(".text")))
myOtherVa1r[] = {0x01, 0x02, 0x03, 0x04};

int main() {
  for (int i = sizeof(myOtherVa1r); i < 0xff; i++) {
    printf("%x ", *(myOtherVa1r + i + 12));
  }
  printf("\n %x\n", myOtherVa1r);
  printf("%d\n", _func());
  printf("%s", buf);

  return 0;
}