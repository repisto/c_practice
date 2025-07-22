// human.h
#ifndef HUMAN_H
#define HUMAN_H
enum { MALE, FEMALE };

typedef struct {
  char name[20];
  int age;
  int gender;
} Human;
Human createHuman(char *name, int age, int gender);
int printHuman(Human *human);
#endif