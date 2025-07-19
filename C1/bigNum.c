#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int i_digit[101];
  int d_digit[101];
  int i_total_digit;
  int d_total_digit;
  char sign;
} BigNum;

int charToInt(char ch);
char intToChar(int i);
void getIntegerAndFractionalParts(char input[], int integerPart[],
                                  int *i_total_digit, int fractionalPart[],
                                  int *d_total_digit);
void performArithmeticOnBigNums();
void intArrayCopy(int dst[], int src[], int len);
int max(int *num1, int *num2);
void addBigNum(BigNum *num1, BigNum *num2, BigNum *result);
void printResult(BigNum *num);

int main() { performArithmeticOnBigNums(); }

int charToInt(char ch) { return ch - '0'; }
char intToChar(int i) { return i + '0'; }
void performArithmeticOnBigNums() {
  BigNum num1 = {0};
  BigNum num2 = {0};
  BigNum result = {0};
  printf("100개 이하의 자리 숫자들의 사칙연산 프로그램입니다.\n");
  char input[202] = {0};

  printf("Input num1: ");
  scanf("%s", input);
  getIntegerAndFractionalParts(input, num1.i_digit, &num1.i_total_digit,
                               num1.d_digit, &num1.d_total_digit);

  printf("Input num2: ");
  scanf("%s", input);
  getIntegerAndFractionalParts(input, num2.i_digit, &num2.i_total_digit,
                               num2.d_digit, &num2.d_total_digit);

  printf("1: add, 2: sub, 3: multiply, 4: divide\n>> ");
  int optionNum = 0;
  scanf("%d", &optionNum);

  while (1) {
    switch (optionNum) {
    case 1:
      addBigNum(&num1, &num2, &result);
      break;
    case 2:
      // sub1000(num1, num2, result, &sign);
      break;
    case 3:
      // mul1000(num1, num2, result);
      break;
    case 4:
      // div1000(num1, num2, result, remainder);
      break;
    default:
      // printf("Wrong input. Try again!\n");
      continue;
    }
    break;
  }

  printResult(&result);
}
void getIntegerAndFractionalParts(char input[], int integerPart[],
                                  int *i_total_digit, int fractionalPart[],
                                  int *d_total_digit) {
  int i = 0;
  for (; input[i] != '.'; i++) {
    integerPart[i] = charToInt(input[i]);
  }
  integerPart[i] = -1; // 정수 끝을 표현하기 위함
  *i_total_digit = i;

  int j = i + 1;
  i = 0;
  for (; input[j] != '\0'; j++) {
    fractionalPart[i++] = charToInt(input[j]);
  }
  fractionalPart[i] = -1;
  *d_total_digit = i;
}
void intArrayCopy(int dst[], int src[], int len) {
  for (int i = 0; i < len; i++) {
    dst[i] = src[i];
  }
}
int max(int *num1, int *num2) { return (*num1 > *num2) ? *num1 : *num2; }
void addBigNum(BigNum *num1, BigNum *num2, BigNum *result) {
  // add fractional part first
  int localFracNum1[101] = {0};
  int localFracNum2[101] = {0};
  intArrayCopy(localFracNum1, num1->d_digit, 101);
  intArrayCopy(localFracNum2, num2->d_digit, 101);
  int len1 = num1->d_total_digit;
  int len2 = num2->d_total_digit;
  int maxLen = max(&len1, &len2);
  result->d_total_digit = maxLen;
  int carry = 0;

  for (int i = maxLen - 1; i >= 0; i--) {
    if (localFracNum1[i] == -1)
      localFracNum1[i] = 0;
    if (localFracNum2[i] == -1)
      localFracNum2[i] = 0;
    int sum = localFracNum1[i] + localFracNum2[i] + carry;
    result->d_digit[i] = sum % 10;
    if (sum >= 10)
      carry = 1;
  }

  int localIntNum1[101] = {0};
  int localIntNum2[101] = {0};
  intArrayCopy(localIntNum1, num1->i_digit, 101);
  intArrayCopy(localIntNum2, num2->i_digit, 101);
  len1 = num1->i_total_digit;
  len2 = num2->i_total_digit;
  maxLen = max(&len1, &len2);
  result->i_total_digit = maxLen;

  for (int i = maxLen - 1; i >= 0; i--) {
    if (localIntNum1[i] == -1)
      localIntNum1[i] = 0;
    if (localIntNum2[i] == -1)
      localIntNum2[i] = 0;
    int sum = localIntNum1[i] + localIntNum2[i] + carry;
    result->i_digit[i] = sum % 10;
    if (sum >= 10)
      carry = 1;
  }
  if (carry == 1) {
    for (int i = result->i_total_digit - 1; i >= 0; i--) {
      result->i_digit[i + 1] = result->i_digit[i];
    }
    result->i_digit[0] = carry;
    result->i_total_digit++;
  }
}
void printResult(BigNum *num) {
  for (int i = 0; i < num->i_total_digit; i++) {
    printf("%d", num->i_digit[i]);
  }
  printf(".");
  for (int i = 0; i < num->d_total_digit; i++) {
    printf("%d", num->d_digit[i]);
  }
  printf("\n");
}
