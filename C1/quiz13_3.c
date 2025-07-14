#include <stdio.h>

int factorial(int num);
int main() {
  printf("calculate factorial program\n");
  printf("Input a number: ");
  int num = 0;
  scanf("%d", &num);
  printf("%d! = %d\n", num, factorial(num));
  return 0;
}
int factorial(int num) {
  if (num == 0 || num == 1)
    return 1;
  else
    return num * factorial(num - 1);
}
