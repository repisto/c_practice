#include <math.h>
#include <stdio.h>

void convertBaseProgram();
int convertBaseNtoM(int num, int digitNum, int n, int m);
int main() {
  convertBaseProgram();
  return 0;
}
void convertBaseProgram() {
  int n = 0;
  int m = 0;
  printf("I will change a number from n base to m base.\n");
  printf("Input n and m: ");
  scanf("%d %d", &n, &m);

  int num = 0;
  printf("Input a %d base number: ", n);
  scanf("%d", &num);
  int numOfDigit = 0;
  printf("Input the number of digits of entered number!!>> ");
  scanf("%d", &numOfDigit);

  int newNum = convertBaseNtoM(num, numOfDigit, n, m);
  printf("n base: %d, m base: %d\n\n", num, newNum);
}
int convertBaseNtoM(int num, int digitNum, int n, int m) {
  int resultBase10 = 0;
  int digit = 0;
  for (int i = 0; i < digitNum; i++) {
    digit = num % 10;
    num /= 10;
    resultBase10 += digit * (int)pow(n, i);
  }
  int resultBaseM = 0;
  int remainder = 0;
  for (int i = 0;; i++) {
    remainder = resultBase10 % m;
    resultBaseM += remainder * (int)pow(10, i);
    resultBase10 /= m;
    if (resultBase10 == 0)
      break;
  }
  return resultBaseM;
}
