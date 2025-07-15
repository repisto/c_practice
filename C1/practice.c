#include <stdio.h>
#include <stdlib.h>

int main() {
  int num = 0;
  char c = 0;

  printf("숫자를 입력하세요: ");
  scanf("%d", &num);

  getchar();

  printf("문자를 입력하세요: ");
  scanf("%c", &c);

  printf("입력한 문자 : %c\n", c);

  return 0;
}
