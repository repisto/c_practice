#include <stdio.h>

void swap(int *num1, int *num2);
int getGCD(int num1, int num2);
void inputArray(int arr[], int len);
int main() {
  printf("Input a number: ");
  int num = 0;
  scanf("%d", &num);

  int arr[num];
  inputArray(arr, num);
  int GCD = arr[0];
  for (int i = 1; i < num; i++) {
    GCD = getGCD(GCD, arr[i]);
  }
  printf("Greatest Common divisor of that array: %d\n", GCD);

  return 0;
}
void swap(int *num1, int *num2) {
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int getGCD(int num1, int num2) {
  while (num2 != 0) {
    int temp = num1 % num2;
    num1 = num2;
    num2 = temp;
  }
  return num1;
}
void inputArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("arr[%d]: ", i);
    scanf("%d", &arr[i]);
  }
}
