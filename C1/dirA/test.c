/*
test.c
여러분과 파일 이름은 다를 수 있습니다.
*/
#include <stdio.h>
char compare(char *str1, char *str2);
int main() {
  char str1[20];
  char str2[20];

  scanf("%s", str1);
  scanf("%s", str2);

  if (compare(str1, str2)) {
    printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);
  } else {
    printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);
  }
  return 0;
}