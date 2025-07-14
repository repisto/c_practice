#include <stdio.h>

void runCalculateProgram();
int inputCalculate(int *result);
void add(int num, int *result);
void sub(int num, int *result);
void mul(int num, int *result);
void div(int num, int *result);
void erase(int *result);
void showEnd();
void showResult(int result);
int main() {
  runCalculateProgram();
  return 0;
}
void runCalculateProgram() {
  int result = 0;
  int endProgram = 0;

  printf("Current number: 0\n\n");
  while (1) {
    endProgram = inputCalculate(&result);
    if (endProgram) {
      showEnd();
      break;
    } else
      showResult(result);
  }
}
int inputCalculate(int *result) {
  int endProgram = 0;
  int endLoop = 1;
  while (1) {

    int optionNum = 0;
    printf("Input option(1. add, 2. sub, 3. multiply, 4. divide, 5. erase, "
           "6. end program)\n>>");
    scanf("%d", &optionNum);

    int num = 0;
    if (optionNum != 5 && optionNum != 6) {
      printf("Input a number: ");
      scanf("%d", &num);
    }

    switch (optionNum) {
    case 1:
      add(num, result);
      break;
    case 2:
      sub(num, result);
      break;
    case 3:
      mul(num, result);
      break;
    case 4:
      div(num, result);
      break;
    case 5:
      erase(result);
      break;
    case 6:
      endProgram = 1;
      break;
    default:
      printf("Wrong input. Try again\n\n");
      endLoop = 0;
      break;
    }
    if (endLoop)
      break;
  }

  return endProgram;
}
void add(int num, int *result) { *result += num; }
void sub(int num, int *result) { *result -= num; }
void mul(int num, int *result) { *result *= num; }
void div(int num, int *result) {
  if (num == 0) {
    printf("Cannot divide by 0.\n");
    return;
  }
  *result /= num;
}
void erase(int *result) { *result = 0; }
void showEnd() { printf("Calculate Program Exit\n\n"); }
void showResult(int result) { printf("Current number: %d\n", result); }