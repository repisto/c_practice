#include <stdio.h>
#include <string.h>

int main() {
  char str1[100] = {0};
  char str2[100] = {0};
  printf("Input str1: ");
  scanf("%s", str1);
  printf("Input str2: ");
  scanf("%s", str2);

  char *pos = strstr(str1, str2);

  if (pos != -1) {
    int searchIndex = pos - str1;
    printf("The first index that %s is involved from %s: %d", str2, str1,
           searchIndex);
  } else
    printf("Substring %s is not found in %s.\n", str2, str1);

  return 0;
}