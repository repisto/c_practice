#include <math.h>
#include <stdio.h>
#include <string.h>

void baseConvertNtoM();
int convertTo10Base(char num[], int n);
void swap(char *ch1, char *ch2);
void convertToMBase(char result[], int base10Num, int m);

int main() {
  baseConvertNtoM();
  return 0;
}
void baseConvertNtoM() {
  printf("Convert from n base number to m base number program****\n");
  printf("Input n,m smaller than 37. Because I can't add more alphabets\n");

  printf("Input n: ");
  int n = 0;
  scanf("%d", &n);
  printf("Input m: ");
  int m = 0;
  scanf("%d", &m);

  if (n < 2 || n > 36 || m < 2 || m > 36) {
    printf("Only supports bases between 2 and 36.\n");
    return;
  }
  printf("Input a number from %d base: \n", n);
  printf("Only input 0~9 and a to z: ");

  char num[30] = {0};
  scanf("%s", num);

  int base10Num = convertTo10Base(num, n);
  printf("10 base num: %d\n\n", base10Num);

  char result[30] = {0};
  convertToMBase(result, base10Num, m);
  printf("%d base num: %s\n", m, result);
}
int convertTo10Base(char num[], int n) {
  int len = strlen(num);
  int base10Num = 0;
  int value = 0;
  char smallLetterDiff = 'a' - 10;
  char bigLetterDiff = 'A' - 10;
  for (int i = 0; i < len; i++) {
    if (num[i] >= '0' && num[i] <= '9') {
      value = num[i] - '0';
    } else if (num[i] >= 'a' && num[i] <= 'z') {
      value = num[i] - smallLetterDiff;
    } else if (num[i] >= 'A' && num[i] <= 'Z') {
      value = num[i] - bigLetterDiff;
    }
    base10Num += value * (int)pow(n, (len - i - 1));
  }
  return base10Num;
}
void swap(char *ch1, char *ch2) {
  char temp = *ch1;
  *ch1 = *ch2;
  *ch2 = temp;
}

void convertToMBase(char result[], int base10Num, int m) {
  int remainder = 0;
  char charRemainder = 0;
  int i = 0;
  while (1) {
    remainder = base10Num % m;
    if (remainder >= 0 && remainder <= 9) {
      charRemainder = remainder + '0';
    } else if (remainder >= 10 && remainder <= 35) {
      charRemainder = remainder + ('A' - 10);
    }
    result[i++] = charRemainder;
    base10Num /= m;
    if (base10Num == 0) {
      result[i] = 0;
      break;
    }
  }
  // reverse result[] order
  int len = strlen(result);
  for (int i = 0; i < len / 2; i++) {
    swap(&result[i], &result[len - i - 1]);
  }
}
