// test.c
#include "str.h"
#include <stdio.h>
int main() {
  char str1[20] = {0};
  char str2[20] = {0};

  scanf("%s", str1);
  scanf("%s", str2);

  if (compare(str1, str2)) {
    printf("%s and %s are same\n", str1, str2);
  } else {
    printf("%s and %s are different.\n", str1, str2);
  }
  return 0;
}