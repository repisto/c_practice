#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate1000digitProgram();
void swap(char *ch1, char *ch2);
void shiftRightMost(char num[], int len);
void shiftLeftMost(char num[], int len);
int charToInt(char ch);
char intToChar(int num);
void add1000base(char num1[], char num2[], int numLen, char result[],
                 int resultLen);
void sub1000base(char num1[], char num2[], int numLen, char result[],
                 int resultLen, int *sign);
void shiftLeftN(char str[], int len, int shiftCount);
void mul1000base(char num1[], char num2[], int numLen, char result[],
                 int resultLen);
void div1000base(char num1[], char num2[], char result[]);

int main() {
  calculate1000digitProgram();
  return 0;
}
void calculate1000digitProgram() {
  char num1[1001] = {0};
  char num2[1001] = {0};
  char result[2001] = {0}; // when we multiply, don't over 2000 digits.
  printf("Input two numbers\n");
  printf("num1: ");
  scanf("%s", num1);
  printf("num2: ");
  scanf("%s", num2);

  int optionNum = 0;
  printf("Enter a number(1: add, 2: sub, 3: mul, 4: div)\n");
  scanf("%d", &optionNum);

  int sign = 0; // 1 is +, -1 is -.

  while (1) {
    switch (optionNum) {
    case 1:
      add1000base(num1, num2, 1001, result, 2001);
      break;
    case 2:
      sub1000base(num1, num2, 1001, result, 2001, &sign);
      break;
    case 3:
      mul1000base(num1, num2, 1001, result, 2001);
      break;
    case 4:
      div1000base(num1, num2, result);
      break;
    default:
      printf("Wrong input! Try again");
      continue;
    }
    break;
  }
  printf("result: ");
  if (sign == -1) {
    printf("-");
  }
  printf("%s\n", result);
}
void swap(char *ch1, char *ch2) {
  char temp = *ch1;
  *ch1 = *ch2;
  *ch2 = temp;
}
void shiftRightMost(char num[], int len) {
  int str_len = strlen(num);
  int shift = len - str_len;

  for (int i = str_len - 1; i >= 0; i--) {
    num[i + shift] = num[i];
  }
  for (int i = 0; i < shift; i++) {
    num[i] = '0';
  }
}
void shiftLeftMost(char num[], int len) {
  int startIndex = 0;
  int i = 0;
  for (; i < len; i++) {
    if (num[i] != '0') {
      startIndex = i;
      break;
    }
  }
  int isEmpty = 0;
  if (i == len) {
    isEmpty = 1;
  }

  if (!isEmpty) {
    int j = 0;
    for (int i = startIndex; i < len; i++) {
      num[j++] = num[i];
    }
    num[j] = '\0';
  } else {
    num[0] = '0';
    num[1] = 0;
  }
}
int charToInt(char ch) {
  if (isdigit(ch))
    return ch - '0';
  else
    return -1;
}
char intToChar(int num) {
  if (num >= 0 && num <= 9)
    return num + '0';
  else
    return -1;
}
void add1000base(char num1[], char num2[], int numLen, char result[],
                 int resultLen) {
  shiftRightMost(num1, numLen);
  shiftRightMost(num2, numLen);
  memset(result, '0', resultLen);

  int carry[1001] = {0};
  int j = resultLen - 1;
  for (int i = numLen - 1; i >= 0; i--) {
    int temp = carry[i] + charToInt(num1[i]) + charToInt(num2[i]);
    if (i > 0)
      carry[i - 1] = temp / 10;
    result[j--] = intToChar(temp % 10);
  }
  shiftLeftMost(result, resultLen);
}
void sub1000base(char num1[], char num2[], int numLen, char result[],
                 int resultLen, int *sign) {
  shiftRightMost(num1, numLen);
  shiftRightMost(num2, numLen);
  memset(result, '0', resultLen);

  int isBig = strcmp(num1, num2);
  if (isBig == 0) {
    result[0] = '0';
    result[1] = 0;
    return;
  } else if (isBig > 0) {
    *sign = 1;
  } else {
    *sign = -1;
  }

  int borrow[1001] = {0};
  int j = resultLen - 1;
  if (*sign == 1) {
    for (int i = numLen - 1; i >= 0; i--) {
      int temp = -borrow[i] + charToInt(num1[i]) - charToInt(num2[i]);
      if (i > 0 && temp < 0) {
        borrow[i - 1] = 1;
        temp += 10;
      }
      result[j--] = intToChar(temp);
    }
  } else {
    for (int i = numLen - 1; i >= 0; i--) {
      int temp = -borrow[i] + charToInt(num2[i]) - charToInt(num1[i]);
      if (i > 0 && temp < 0) {
        borrow[i - 1] = 1;
        temp += 10;
      }
      result[j--] = intToChar(temp);
    }
  }
  shiftLeftMost(result, resultLen);
}
void shiftLeftN(char str[], int len, int shiftCount) {
  int firstIndex = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] != '0') {
      firstIndex = i;
      break;
    }
  }
  for (int i = firstIndex; i < len; i++) {
    if ((i - shiftCount) >= 0) {
      str[i - shiftCount] = str[i];
      str[i] = '0';
    }
  }
}

void mul1000base(char num1[], char num2[], int numLen, char result[],
                 int resultLen) {
  // 0을 곱하는 경우 처리
  if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
    strcpy(result, "0");
    return;
  }

  int len1 = strlen(num1);
  int len2 = strlen(num2);
  int res_len = len1 + len2;

  // 결과를 저장할 정수 배열 동적 할당 및 0으로 초기화
  int *res_int = (int *)calloc(res_len, sizeof(int));
  if (res_int == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  // 세로셈 곱셈 수행 (오른쪽 -> 왼쪽)
  int i_n1 = 0;
  int i_n2 = 0;

  for (int i = len1 - 1; i >= 0; i--) {
    int carry = 0;
    int n1 = charToInt(num1[i]);
    i_n2 = 0;

    for (int j = len2 - 1; j >= 0; j--) {
      int n2 = charToInt(num2[j]);

      // 현재 자릿수의 곱셈 결과 + 이전 계산에서 더해진 값 + 올림(carry)
      int sum = n1 * n2 + res_int[i_n1 + i_n2] + carry;

      // 올림(carry) 계산
      carry = sum / 10;

      // 현재 자릿수 결과 저장
      res_int[i_n1 + i_n2] = sum % 10;

      i_n2++;
    }

    // 마지막 올림 처리
    if (carry > 0) {
      res_int[i_n1 + i_n2] += carry;
    }

    i_n1++;
  }

  // 결과 문자열에서 앞쪽의 불필요한 '0' 제거
  int i = res_len - 1;
  while (i >= 0 && res_int[i] == 0) {
    i--;
  }

  // 모든 숫자가 0인 경우 (결과가 0)
  if (i == -1) {
    strcpy(result, "0");
    free(res_int);
    return;
  }

  // 정수 배열 결과를 최종 문자열로 변환
  int k = 0;
  while (i >= 0) {
    result[k++] = intToChar(res_int[i--]);
  }
  result[k] = '\0'; // 문자열의 끝을 표시

  // 동적 할당한 메모리 해제
  free(res_int);
}
void div1000base(char num1[], char num2[], char result[]) {
  // 0으로 나누는 경우 처리
  if (strcmp(num2, "0") == 0) {
    printf("Error: Division by zero\n");
    strcpy(result, "0");
    return;
  }

  // 0을 나누는 경우 처리
  if (strcmp(num1, "0") == 0) {
    strcpy(result, "0");
    return;
  }

  int len1 = strlen(num1);
  int len2 = strlen(num2);
  char temp[1002] = {0};
  char temp_result[1002] = {0};
  int res_index = 0;

  int temp_index = 0;
  int i = 0;

  // 몫을 한 자리씩 계산
  while (i < len1) {
    // temp = temp * 10 + num1[i]
    temp[temp_index++] = num1[i++];
    temp[temp_index] = '\0';
    shiftLeftMost(temp, temp_index);

    int count = 0;
    while (strcmp(temp, num2) >= 0) {
      // temp -= num2
      char sub_result[1002] = {0};
      int sign = 0;
      sub1000base(temp, num2, 1001, sub_result, 1001, &sign);
      strcpy(temp, sub_result);
      temp_index = strlen(temp);
      count++;
    }

    temp_result[res_index++] = intToChar(count);
  }

  temp_result[res_index] = '\0';
  shiftLeftMost(temp_result, 1002);
  strcpy(result, temp_result);
}
