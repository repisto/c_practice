// human.c
#include "human.h"
#include <stdio.h>
#include <string.h>
Human createHuman(char *name, int age, int gender) {
  Human human = {0};
  human.age = age;
  human.gender = gender;
  strcpy(human.name, name);

  return human;
}
int printHuman(Human *human) {
  printf("Name : %s\n", human->name);
  printf("Age : %d\n", human->age);
  if (human->gender == MALE) {
    printf("Gender : Male\n");
  } else if (human->gender == FEMALE) {
    printf("Gender : Female\n");
  }
  return 0;
}
