#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate1000digitProgram();
void swap(char *ch1, char *ch2);
void strReverse(char str[]);
int max(int num1, int num2);
int charToInt(char ch);
char intToChar(int num);
void trimLeadingZeros(char *str);
void add1000(char num1[], char num2[], char result[]);
void sub1000(char num1[], char num2[], char result[], int *sign);
void mul1000(char num1[], char num2[], char result[]);
int compareStr(const char num1[], const char num2[]);
void subtractStr(char num1[], const char num2[], char result[]);
void div1000(char num1[], char num2[], char result[], char remainder[]);

int main() {
  calculate1000digitProgram();
  return 0;
}
void calculate1000digitProgram() {
  printf("1000의 자리 숫자들의 사칙연산 프로그램입니다.\n");
  printf("Input num1: ");
  char num1[1001] = {0};
  scanf("%s", num1);
  printf("Input num2: ");
  char num2[1001] = {0};
  scanf("%s", num2);

  printf("1: add, 2: sub, 3: multiply, 4: divide\n>> ");
  int optionNum = 0;
  scanf("%d", &optionNum);

  char result[2001] = {0};
  int sign = 1; // 1 is positive, -1 is negative, 0 is 0
  int error = 0;
  char remainder[1001] = {0};

  while (1) {
    switch (optionNum) {
    case 1:
      add1000(num1, num2, result);
      break;
    case 2:
      sub1000(num1, num2, result, &sign);
      break;
    case 3:
      mul1000(num1, num2, result);
      break;
    case 4:
      div1000(num1, num2, result, remainder);
      break;
    default:
      printf("Wrong input. Try again!\n");
      continue;
    }
    break;
  }

  if (strcmp("NaN", result) == 0) {
    printf("NaN\n");
    return;
  }
  printf("result: ");
  if (sign == -1) {
    printf("-");
  }
  printf("%s\n", result);

  if (optionNum == 4)
    printf("remainder: %s\n", remainder);
}
void swap(char *ch1, char *ch2) {
  char temp = *ch1;
  *ch1 = *ch2;
  *ch2 = temp;
}
void strReverse(char str[]) {
  int len = strlen(str);
  for (int i = 0; i < (len / 2); i++) {
    swap(&str[i], &str[len - 1 - i]);
  }
}
int max(int num1, int num2) { return num1 > num2 ? num1 : num2; }
int charToInt(char ch) { return ch - '0'; }
char intToChar(int num) { return num + '0'; }
void trimLeadingZeros(char *str) {
  while (str[0] == '0' && strlen(str) > 1)
    memmove(str, str + 1, strlen(str));
}

void add1000(char num1[], char num2[], char result[]) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  int maxLen = max(len1, len2);
  char revNum1[1001] = {0};
  char revNum2[1001] = {0};
  strcpy(revNum1, num1);
  strcpy(revNum2, num2);
  strReverse(revNum1);
  strReverse(revNum2);

  int tempResult[1001] = {0};
  int carry = 0;
  int i = 0;
  for (; i < maxLen; i++) {
    if (revNum1[i] == '\0') {
      revNum1[i] = '0';
    }
    if (revNum2[i] == '\0') {
      revNum2[i] = '0';
    }
    int temp = charToInt(revNum1[i]) + charToInt(revNum2[i]) + carry;
    tempResult[i] = temp % 10;
    carry = temp / 10;
  }
  if (carry == 1) {
    tempResult[i++] = carry;
  }
  int j = 0;
  for (; j < i; j++) {
    result[j] = intToChar(tempResult[j]);
  }
  result[j] = '\0';
  strReverse(result);
}
void sub1000(char num1[], char num2[], char result[], int *sign) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  int maxLen = max(len1, len2);
  char revNum1[1001] = {0};
  char revNum2[1001] = {0};
  strcpy(revNum1, num1);
  strcpy(revNum2, num2);
  strReverse(revNum1);
  strReverse(revNum2);

  int isNum1Big = 0;
  if (len1 > len2) {
    isNum1Big = 1;
    *sign = 1;
  } else if (len1 < len2) {
    isNum1Big = 0;
    *sign = -1;
  } else if (strcmp(num1, num2) == 0) {
    *sign = 0;
    result[0] = '0';
    result[1] = '\0';
    return;
  } else if (strcmp(num1, num2) > 0) {
    isNum1Big = 1;
    *sign = 1;
  } else {
    isNum1Big = 0;
    *sign = -1;
  }
  int tempResult[1001] = {0};
  int borrow = 0;
  int i = 0;
  if (isNum1Big) {
    for (; i < maxLen; i++) {
      if (revNum1[i] == '\0') {
        revNum1[i] = '0';
      }
      if (revNum2[i] == '\0') {
        revNum2[i] = '0';
      }
      int temp = charToInt(revNum1[i]) - charToInt(revNum2[i]) - borrow;
      if (temp < 0) {
        borrow = 1;
        temp += 10;
      }
      tempResult[i] = temp;
    }
  } else {
    for (; i < maxLen; i++) {
      if (revNum1[i] == '\0') {
        revNum1[i] = '0';
      }
      if (revNum2[i] == '\0') {
        revNum2[i] = '0';
      }
      int temp = charToInt(revNum2[i]) - charToInt(revNum1[i]) - borrow;
      if (temp < 0) {
        borrow = 1;
        temp += 10;
      }
      tempResult[i] = temp;
    }
  }
  int j = 0;
  for (; j < i; j++) {
    result[j] = intToChar(tempResult[j]);
  }
  result[j] = '\0';
  j = strlen(result) - 1;
  while (j > 0 && result[j] == '0') {
    result[j--] = '\0';
  }
  strReverse(result);
}
void mul1000(char num1[], char num2[], char result[]) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  char revNum1[1001] = {0};
  char revNum2[1001] = {0};
  strcpy(revNum1, num1);
  strcpy(revNum2, num2);
  strReverse(revNum1);
  strReverse(revNum2);

  int tempResult[2001] = {0};

  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      int temp = charToInt(revNum1[i]) * charToInt(revNum2[j]);
      tempResult[i + j] += temp;

      int k = i + j;
      while (tempResult[k] >= 10) {
        tempResult[k + 1] += tempResult[k] / 10;
        tempResult[k] %= 10;
        k++;
      }
    }
  }
  int resultLen = len1 + len2;
  while (resultLen > 1 && tempResult[resultLen - 1] == 0) {
    resultLen--;
  }
  for (int i = 0; i < resultLen; i++) {
    result[i] = intToChar(tempResult[i]);
  }
  result[resultLen] = '\0';
  strReverse(result);
}
int compareStr(const char num1[], const char num2[]) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  if (len1 > len2)
    return 1;
  if (len1 < len2)
    return -1;
  return strcmp(num1, num2);
}
void subtractStr(char num1[], const char num2[], char result[]) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  char rev1[1001] = {0}, rev2[1001] = {0};
  strcpy(rev1, num1);
  strcpy(rev2, num2);
  strReverse(rev1);
  strReverse(rev2);

  int borrow = 0;
  int i = 0;
  int tempResult[1001] = {0};
  for (; i < len1; i++) {
    int digit1 = rev1[i] ? charToInt(rev1[i]) : 0;
    int digit2 = rev2[i] ? charToInt(rev2[i]) : 0;

    int sub = digit1 - digit2 - borrow;
    if (sub < 0) {
      sub += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    tempResult[i] = sub;
  }

  // 뒤집고 앞 0 제거
  int j = i - 1;
  while (j > 0 && tempResult[j] == 0)
    j--;

  for (int k = 0; k <= j; k++) {
    result[k] = intToChar(tempResult[k]);
  }
  result[j + 1] = '\0';
  strReverse(result);
}

void div1000(char num1[], char num2[], char result[], char remainder[]) {
  if (compareStr(num2, "0") == 0) {
    strcpy(result, "NaN");
    remainder[0] = '0';
    remainder[1] = '\0';
    return;
  }

  char current[1001] = {0}; // 현재 계산중인 부분 피제수
  char temp[1001] = {0};    // 뺄셈 결과 저장용
  int len1 = strlen(num1);
  int resIndex = 0;
  int curIndex = 0;

  for (int i = 0; i < len1; i++) {
    current[curIndex++] = num1[i];
    current[curIndex] = '\0';

    // 앞자리 0 제거
    while (current[0] == '0' && strlen(current) > 1)
      memmove(current, current + 1, strlen(current));

    int q = 0;
    while (compareStr(current, num2) >= 0) {
      subtractStr(current, num2, temp);
      strcpy(current, temp);
      curIndex = strlen(current);
      q++;
    }
    result[resIndex++] = intToChar(q);
  }

  result[resIndex] = '\0';

  // 앞자리 0 제거
  int start = 0;
  while (result[start] == '0' && start < resIndex - 1)
    start++;
  if (start > 0)
    memmove(result, result + start, resIndex - start + 1);
  current[curIndex] = '\0';
  strcpy(remainder, current);
}
