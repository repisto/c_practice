#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TEST {
  int age;
  int gender;
  char name[20];
};
int set_human(struct TEST *a, int age, int gender, const char *name);
int main() {
  struct TEST human = {0};
  set_human(&human, 10, 1, "Lee");
  printf("AGE: %d // Gender: %d // Name : %s\n", human.age, human.gender,
         human.name);

  return 0;
}
int set_human(struct TEST *a, int age, int gender, const char *name) {
  a->age = age;
  a->gender = gender;
  strcpy(a->name, name);
  return 0;
}
