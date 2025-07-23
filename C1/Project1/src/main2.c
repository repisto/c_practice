// main2.c
#include <stdio.h>
#define B

int main() {
#ifdef A
  printf("AAAA\n");
#endif
#ifdef B
  printf("BBBB\n");
#endif
  return 0;
}