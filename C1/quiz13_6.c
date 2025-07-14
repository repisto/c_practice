#include <stdio.h>

void printPrimeNumProgram();
int getN();
void printPrimeNum(int num);

int main() { printPrimeNumProgram(); }
void printPrimeNumProgram() {
  printf("This program prints all the prime numbers from 1 to N.\n");
  printf("You input N!\n");
  int num = getN();
  printPrimeNum(num);
}
int getN() {
  printf("Enter N: ");
  int n = 0;
  scanf("%d", &n);
  return n;
}
void printPrimeNum(int num) {
  int isPrime[num + 1];
  for (int i = 0; i <= num; i++) {
    isPrime[i] = 1;
  }
  isPrime[0] = 0;
  isPrime[1] = 0;

  for (int i = 2; i * i <= num; i++) {
    for (int j = i * i; j <= num; j += i) {
      isPrime[j] = 0;
    }
  }

  for (int i = 2; i <= num; i++) {
    if (isPrime[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("\n");
}
