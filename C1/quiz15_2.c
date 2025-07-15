#include <stdio.h>
#include <string.h>

void convertCaseLetter(char str[]);
int main() {
  char str1[100] = {0};
  char str2[100] = {0};

  return 0;
}
void convertCaseLetter(char str[]) {
  int diff = 'a' - 'A'; // positive
  for (int i = 0; str[i] != 0; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= diff;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += diff;
    }
  }
}
