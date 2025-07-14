#include <stdio.h>

void calculate1000digitProgram();
void add1000base(char num1[], char num2[], char total[]);
void shiftRightMost(char num1[], int len);

int main() {
  calculate1000digitProgram();
  return 0;
}
void calculate1000digitProgram() {
  char num1[1001] = {0};
  char num2[1001] = {0};
  char total[2001] = {0}; // when we multiply, don't over 2000 digits.
  printf("Input two numbers\n");
  printf("num1: %s", num1);
  printf("num2: %s", num2);
  int optionNum = 0;
  printf("Enter a number(1: add, 2: sub, 3: mul, 4: div\n)");
  while (1) {
    switch (optionNum) {
    case 1:
      add1000base(num1, num2, total);
      break;
    case 2:
      sub1000base(num1, num2, total);
      break;
    case 3:
      mul1000base(num1, num2, total);
      break;
    case 4:
      div1000base(num1, num2, total);
      break;
    default:
      printf("Wrong input! Try again");
      continue;
    }
    break;
  }
  printf("result: %s\n", total);
}
void add1000base(char num1[], char num2[], char total[]) {
  shiftRightMost(num1, (int)strlen(num1));
  shiftRightMost(num2, (int)strlen(num2));
}
void shiftRightMost(char num1[], int len) {}
