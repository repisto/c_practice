// bookManage.c
#include "bookManage.h"
#include <stdio.h>
#include <string.h>

void bookManageProgram() {
  printf("-------Book Manage Program-------\n");
  printf("Max count of books is 100.\n\n");

  Book bookArray[100] = {0};
  int isEnd = 0;

  while (1) {
    showOptions();
    int optionNum = inputOptionNum();
    switch (optionNum) {
    case -1:
      showExitProgram();
      isEnd = 1;
      break;
    case 1:
      registerBook(bookArray);
      break;
    case 2:
      searchBook(bookArray);
      break;
    case 3:
      borrowBook(bookArray);
      break;
    case 4:
      returnBook(bookArray);
      break;
    default:
      showInvalidInput();
      continue;
    }
    if (isEnd)
      break;
  }
}
void showOptions() {
  printf("\n------Input Options-----\n");
  printf("-1: exit program\n");
  printf("1: register a book\n");
  printf("2: search a book\n");
  printf("3: borrow a book\n");
  printf("4: return a book\n");
}
int inputOptionNum() {
  printf(">> ");
  int optionNum = 0;
  scanf("%d", &optionNum);
  return optionNum;
}
void showExitProgram() { printf("\n------Exit Program------\n"); }
void showInvalidInput() { printf("Wrong input! Try again!\n"); }
void registerBook(Book bookArray[]) {
  int i = 0;
  while (i < 100 && bookArray[i].isBookExist == 1) {
    i++;
  }
  if (i >= 100) {
    printf("Book system is full!!\n");
    printf("You can't add a book...\n");
    return;
  }
  printf("\nRegister a book!!!\n");

  bookArray[i].isBookExist = 1;
  bookArray[i].bookIndex = i;

  char title[100] = {0};
  printf("Input title: ");
  scanf("%s", title);
  strcpy(bookArray[i].title, title);

  char author[100] = {0};
  printf("Input author: ");
  scanf("%s", author);
  strcpy(bookArray[i].author, author);

  char publisher[100] = {0};
  printf("Input publisher: ");
  scanf("%s", publisher);
  strcpy(bookArray[i].publisher, publisher);

  bookArray[i].borrowed = 0;
}
void searchBook(Book bookArray[]) {
  printf("\n------Search books------\n");
  printf("Which info do you want to search?\n");
  printf("1: title\n");
  printf("2: author\n");
  printf("3: publisher\n");
  int optionNum = inputOptionNum();

  int isEnd = 0;
  while (1) {
    switch (optionNum) {
    case 1:
      searchBookByTitle(bookArray);
      isEnd = 1;
      break;
    case 2:
      searchBookByAuthor(bookArray);
      isEnd = 1;
      break;
    case 3:
      searchBookByPublisher(bookArray);
      isEnd = 1;
      break;
    default:
      showInvalidInput();
      continue;
    }
    if (isEnd)
      break;
  }
}
void printBookInfo(const Book *book) {
  printf("\n--------------\n");
  printf("Book index = %d\n", book->bookIndex);
  printf("title: %s\n", book->title);
  printf("author: %s\n", book->author);
  printf("publisher: %s\n", book->publisher);
  printf("Is borrowed: ");
  if (book->borrowed) {
    printf("yes\n");
  } else
    printf("no\n");
}
void searchBookByTitle(Book bookArray[]) {
  printf("title: ");
  char title[100] = {0};
  scanf("%s", title);

  int isFound = 0;
  for (int i = 0; bookArray[i].isBookExist != 0; i++) {
    if (strcmp(bookArray[i].title, title) == 0) {
      isFound = 1;
      printBookInfo(&bookArray[i]);
    }
  }
  if (isFound == 0) {
    printf("That book is not found!!!\n");
  }
}
void searchBookByAuthor(Book bookArray[]) {
  printf("author: ");
  char author[100] = {0};
  scanf("%s", author);

  int isFound = 0;
  for (int i = 0; bookArray[i].isBookExist != 0; i++) {
    if (strcmp(bookArray[i].author, author) == 0) {
      isFound = 1;
      printBookInfo(&bookArray[i]);
    }
  }
  if (isFound == 0) {
    printf("That book is not found!!!\n");
  }
}
void searchBookByPublisher(Book bookArray[]) {
  printf("publisher: ");
  char publisher[100] = {0};
  scanf("%s", publisher);

  int isFound = 0;
  for (int i = 0; bookArray[i].isBookExist != 0; i++) {
    if (strcmp(bookArray[i].publisher, publisher) == 0) {
      isFound = 1;
      printBookInfo(&bookArray[i]);
    }
  }
  if (isFound == 0) {
    printf("That book is not found!!!\n");
  }
}
void borrowBook(Book bookArray[]) {
  printf("Borrow a book!!!\n");
  printf("Input title: ");
  char title[100] = {0};
  scanf("%s", title);
  int isFound = 0;

  for (int i = 0; bookArray[i].isBookExist != 0; i++) {
    if (strcmp(bookArray[i].title, title) == 0) {
      isFound = 1;
      if (bookArray[i].borrowed == 1) {
        printf("That book is already borrowed... Sorry\n");
      } else {
        bookArray[i].borrowed = 1;
        printf("Borrow Success!!\n");
      }
    }
  }

  if (isFound == 0) {
    printf("That book is not found!!\n");
  }
}
void returnBook(Book bookArray[]) {
  printf("Return a book!!!\n");
  printf("Input title: ");
  char title[100] = {0};
  scanf("%s", title);
  int isFound = 0;

  for (int i = 0; bookArray[i].isBookExist != 0; i++) {
    if (strcmp(bookArray[i].title, title) == 0) {
      isFound = 1;
      if (bookArray[i].borrowed == 0) {
        printf("That book is already returned... Sorry\n");
      } else {
        bookArray[i].borrowed = 0;
        printf("Return Success!!\n");
      }
    }
  }

  if (isFound == 0) {
    printf("That book is not found!!\n");
  }
}
