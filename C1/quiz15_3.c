#include <stdio.h>
#include <string.h>

void printCompareString();
int main() {
  printCompareString();
  return 0;
}
void printCompareString() {
  printf("Enter string1: ");
  char str1[100] = {0};
  scanf("%s", str1);

  printf("Enter string2: ");
  char str2[100] = {0};
  scanf("%s", str2);

  if (strcmp(str1, str2) == 0) {
    printf("Same\n");
  } else
    printf("Different\n");
}
