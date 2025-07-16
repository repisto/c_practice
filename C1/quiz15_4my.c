#include <stdio.h>
#include <string.h>

int mystrstr(char str1[], char str2[]);

int main() {
  char str1[100] = {0};
  char str2[100] = {0};

  printf("Enter string1: ");
  scanf("%s", str1);
  printf("Enter string2: ");
  scanf("%s", str2);

  int firstIndex = mystrstr(str1, str2);

  if (firstIndex != -1)
    printf("first index that %s is included in the %s: %d\n", str2, str1,
           firstIndex);
  else
    printf("There is no %s in the %s.\n", str2, str1);

  return 0;
}
int mystrstr(char str1[], char str2[]) {
  int str1Len = strlen(str1);
  int str2Len = strlen(str2);
  int i = 0;
  int findIndex = -1;
  for (; i <= str1Len - str2Len; i++) {
    int j = i;
    int k = 0;
    for (; k < str2Len; j++, k++) {
      if (str1[j] != str2[k]) {
        break;
      }
    }
    if (k == str2Len) {
      findIndex = i;
      break;
    }
  }
  return findIndex;
}
