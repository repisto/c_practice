#include <stdio.h>
#include <string.h>

typedef struct {
  char title[100];
  char author[100];
  char publisher[100];
  int isBorrowed;
} Book;
void manageBooksProgram();
void showOptions();
int inputOptionNum();
void showExitProgram();
void addBook(Book bookArray[]);
void searchByTitle(Book bookArray[]);
void searchByAuthor(Book bookArray[]);
void searchByPublisher(Book bookArray[]);
void borrowBook(Book bookArray[]);
void returnBook(Book bookArray[]);
void showInvalidInput();

int main() {
  manageBooksProgram();
  return 0;
}
void manageBooksProgram() {
  Book bookArray[100] = {0};

  printf("Book Manage Program ********\n");
  while (1) {
    int isExit = 0;
    showOptions();
    int optionNum = inputOptionNum();
    switch (optionNum) {
    case -1:
      showExitProgram();
      isExit = 1;
      break;
    case 1:
      addBook(bookArray);
      break;
    case 2:
      searchByTitle(bookArray);
      break;
    case 3:
      searchByAuthor(bookArray);
      break;
    case 4:
      searchByPublisher(bookArray);
      break;
    case 5:
      borrowBook(bookArray);
      break;
    case 6:
      returnBook(bookArray);
      break;
    default:
      showInvalidInput();
      break;
    }
    if (isExit)
      break;
  }
}
void showOptions() {
  printf("\n1: add a book\n");
  printf("2: search by title\n");
  printf("3: search by author\n");
  printf("4: search by publisher\n");
  printf("5: borrow a book\n");
  printf("6: return a book\n");
  printf("-1: exit program\n");
}
int inputOptionNum() {
  printf(">> ");
  int optionNum = 0;
  scanf("%d", &optionNum);
  return optionNum;
}
void showExitProgram() { printf("Program exit!!\n\n"); }
void addBook(Book bookArray[]) {
  int i = 0;
  while (i < 100 && bookArray[i].title[0] != 0) {
    i++;
  }
  printf("Input book data!!!\n");
  printf("title: ");
  char title[100] = {0};
  scanf("%s", title);
  strcpy(bookArray[i].title, title);

  printf("author: ");
  char author[100] = {0};
  scanf("%s", author);
  strcpy(bookArray[i].author, author);

  printf("publisher: ");
  char publisher[100] = {0};
  scanf("%s", publisher);
  strcpy(bookArray[i].publisher, publisher);

  printf("Add a book info End!!!!!\n");
}
void searchByTitle(Book bookArray[]) {
  printf("Search By title!!!\n");
  printf("title: ");
  char title[100] = {0};
  scanf("%s", title);

  int i = 0;
  int isFind = 0;
  for (; i < 100; i++) {
    if (strcmp(bookArray[i].title, title))
      continue;
    else {
      isFind = 1;
      printf("\nFind that book!!!\n");
      printf("Book index: %d\n", i);
      printf("title: %s\n", bookArray[i].title);
      printf("author: %s\n", bookArray[i].author);
      printf("publisher: %s\n", bookArray[i].publisher);
      printf("isBorrowd: %d\n", bookArray[i].isBorrowed);
    }
  }
  if (isFind == 0) {
    printf("I can't find that book!\n");
  }
}
void searchByAuthor(Book bookArray[]) {
  printf("Search By author!!!\n");
  printf("author: ");
  char author[100] = {0};
  scanf("%s", author);

  int i = 0;
  int isFind = 0;
  for (; i < 100; i++) {
    if (strcmp(bookArray[i].author, author))
      continue;
    else {
      isFind = 1;
      printf("\nFind that book!!!\n");
      printf("Book index: %d\n", i);
      printf("title: %s\n", bookArray[i].title);
      printf("author: %s\n", bookArray[i].author);
      printf("publisher: %s\n", bookArray[i].publisher);
      printf("isBorrowd: %d\n", bookArray[i].isBorrowed);
    }
  }
  if (isFind == 0) {
    printf("I can't find that book!\n");
  }
}
void searchByPublisher(Book bookArray[]) {
  printf("Search By publisher!!!\n");
  printf("publisher: ");
  char publisher[100] = {0};
  scanf("%s", publisher);

  int i = 0;
  int isFind = 0;
  for (; i < 100; i++) {
    if (strcmp(bookArray[i].publisher, publisher))
      continue;
    else {
      isFind = 1;
      printf("\nFind that book!!!\n");
      printf("Book index: %d\n", i);
      printf("title: %s\n", bookArray[i].title);
      printf("author: %s\n", bookArray[i].author);
      printf("publisher: %s\n", bookArray[i].publisher);
      printf("isBorrowd: %d\n", bookArray[i].isBorrowed);
    }
  }
  if (isFind == 0) {
    printf("I can't find that book!\n");
  }
}
void borrowBook(Book bookArray[]) {
  printf("Borrow a book!!!\n");
  printf("title: ");
  char title[100] = {0};
  scanf("%s", title);

  int i = 0;
  int isFind = 0;
  for (; i < 100; i++) {
    if (strcmp(bookArray[i].title, title))
      continue;
    else {
      isFind = 1;
      printf("\nFind that book!!!\n");
      if (bookArray[i].isBorrowed == 0) {
        printf("You borrowed %s!!\n", title);
        bookArray[i].isBorrowed = 1;
      } else {
        printf("That book is already borrowed... Sorry\n");
      }
    }
  }
  if (isFind == 0) {
    printf("I can't find that book!\n");
  }
}
void returnBook(Book bookArray[]) {
  printf("Return a book!!!\n");
  printf("title: ");
  char title[100] = {0};
  scanf("%s", title);

  int i = 0;
  int isFind = 0;
  for (; i < 100; i++) {
    if (strcmp(bookArray[i].title, title))
      continue;
    else {
      isFind = 1;
      printf("\nFind that book!!!\n");
      if (bookArray[i].isBorrowed == 1) {
        printf("You returned %s!!\n", title);
        bookArray[i].isBorrowed = 0;
      } else {
        printf("That book is already returned... What the fuck is your "
               "book?????\n");
      }
    }
  }
  if (isFind == 0) {
    printf("I can't find that book!\n");
  }
}
void showInvalidInput() { printf("Wrong input! Try again!!\n\n"); }
