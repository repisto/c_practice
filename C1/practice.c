#include <stdio.h>

struct Human {
  int age;
  int height;
  int weight;
};

int main() {
  struct Human Psi = {0};
  Psi.age = 99;
  Psi.height = 185;
  Psi.weight = 80;

  printf("Psi information\n");
  printf("age: %d\n", Psi.age);
  printf("height: %d\n", Psi.height);
  printf("weight: %d\n", Psi.weight);

  return 0;
}
