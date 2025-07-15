#include <stdio.h>
#include <stdlib.h>

int myStrLen(const char str[]);
void myStrCpy(char dst[], char src[]);
int myStrCmp(char str1[], char str2[]);
void myStrCat(char dst[], char stc[]);

int main() {
  char str1[] = "hello";
  char str2[100] = "I am korean.";
  myStrCat(str2, str1);
  printf("%s\n", str2);

  return 0;
}
int myStrLen(const char str[]) {
  int len = 0;
  while (*str++)
    len++;
  return len;
}
void myStrCpy(char dst[], char src[]) {
  int i = 0;
  for (; src[i] != 0; i++) {
    dst[i] = src[i];
  }
  dst[i] = 0;
}
int myStrCmp(char str1[], char str2[]) {
  int i = 0;
  while (str1[i] != 0 && str2[i] != 0) {
    if (str1[i] != str2[i])
      return str1[i] - str2[i]; // 양수가 나올경우 str1이 사전순으로 뒤에 있다.
    i++;
  }
  if (str1[i] != str2[i]) {
    return str1[i] - str2[i];
  }
  return 0;
}
void myStrCat(char dst[], char src[]) {
  int i = 0;
  for (; dst[i] != 0; i++) {
  }
  for (int j = 0; src[j] != 0; i++, j++) {
    dst[i] = src[j];
  }
  dst[i] = 0;
}
