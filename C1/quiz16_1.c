#include <stdio.h>
#include <string.h>

typedef struct {
  char title[100];
  char author[100];
  char publisher[100];
  int isBorrowed;
} Book;

void bookManageProgram();
void showOptions();
int inputOptionNum();
void showExitProgram();
void addBook(Book booksArray[]);
void searchBook(Book booksArray[]);
void printBookInfo(const Book *book);
void searchBookByTitle(Book booksArray[]);
void searchBookByAuthor(Book booksArray[]);
void searchBookByPublisher(Book booksArray[]);
void borrowBook(Book booksArray[]);
void returnBook(Book booksArray[]);
void showInvalidInput();

int main() {
  bookManageProgram();
  return 0;
}
void bookManageProgram() {
  Book booksArray[100] = {0};
  int isEnd = 0;
  printf("*****Book Manage Program*****\n\n");

  while (1) {
    showOptions();
    int optionNum = inputOptionNum();
    switch (optionNum) {
    case -1:
      showExitProgram();
      isEnd = 1;
      break;
    case 1:
      addBook(booksArray);
      break;
    case 2:
      searchBook(booksArray);
      break;
    case 3:
      borrowBook(booksArray);
      break;
    case 4:
      returnBook(booksArray);
      break;
    default:
      showInvalidInput();
    }
    if (isEnd)
      break;
  }
}
void showOptions() {
  printf("1: Add a book\n");
  printf("2: Search a book\n");
  printf("3: Borrow a book\n");
  printf("4: Return a book\n");
  printf("-1: Exit program\n");
}
int inputOptionNum() {
  printf(">> ");
  int optionNum = 0;
  scanf("%d", &optionNum);
  return optionNum;
}
void showExitProgram() { printf("\n*****Exit Book Manage Program*****\n"); }
void addBook(Book booksArray[]) {
  int i = 0;
  while (i < 100 && booksArray[i].title[0] != 0) {
    i++;
  }
  if (i >= 100) {
    printf("Full of books!! Can't add a book!!\n\n");
    return;
  }

  printf("Add a book INFO!!\n");
  printf("title: ");
  char title[100] = {0};
  scanf("%s", title);

  printf("author: ");
  char author[100] = {0};
  scanf("%s", author);

  printf("publisher: ");
  char publisher[100] = {0};
  scanf("%s", publisher);

  strcpy(booksArray[i].title, title);
  strcpy(booksArray[i].author, author);
  strcpy(booksArray[i].publisher, publisher);

  printf("Add a book Info End!!\n");
}
void searchBook(Book booksArray[]) {

  int isEnd = 0;
  while (1) {
    printf("Which option do you want?\n");
    printf("1: search by title\n");
    printf("2: search by author\n");
    printf("3: search by publisher\n");
    printf(">> ");
    int optionNum = 0;
    scanf("%d", &optionNum);
    switch (optionNum) {
    case 1:
      searchBookByTitle(booksArray);
      isEnd = 1;
      break;
    case 2:
      searchBookByAuthor(booksArray);
      isEnd = 1;
      break;
    case 3:
      searchBookByPublisher(booksArray);
      isEnd = 1;
      break;
    default:
      printf("Wrong input. Try again!\n\n");
    }
    if (isEnd)
      break;
  }
}
void printBookInfo(const Book *book) {
  printf("title: %s\n", book->title);
  printf("author: %s\n", book->author);
  printf("publisher: %s\n", book->publisher);
  printf("Is borrowed: ");
  if (book->isBorrowed) {
    printf("Yes\n");
  } else
    printf("No\n");
  printf("\n");
}

void searchBookByTitle(Book booksArray[]) {
  char title[100] = {0};
  printf("title: ");
  scanf("%s", title);
  int isFind = 0;
  // only special for searching by title. substring can be searched.
  for (int i = 0; booksArray[i].title[0] != 0; i++) {
    if (strstr(booksArray[i].title, title) != 0) {
      printf("book index: %d\n", i);
      printBookInfo(&booksArray[i]);
      isFind = 1;
    }
  }

  if (isFind)
    return;
  else {
    printf("%s is not found!!\n\n", title);
  }
}
void searchBookByAuthor(Book booksArray[]) {
  char author[100] = {0};
  printf("author: ");
  scanf("%s", author);
  int isFind = 0;
  for (int i = 0; booksArray[i].author[0] != 0; i++) {
    if (strcmp(booksArray[i].author, author) == 0) {
      printf("book index: %d\n", i);
      printBookInfo(&booksArray[i]);
      isFind = 1;
    }
  }

  if (isFind)
    return;
  else {
    printf("%s is not found!!\n\n", author);
  }
}
void searchBookByPublisher(Book booksArray[]) {
  char publisher[100] = {0};
  printf("publisher: ");
  scanf("%s", publisher);
  int isFind = 0;
  for (int i = 0; booksArray[i].publisher[0] != 0; i++) {
    if (strcmp(booksArray[i].publisher, publisher) == 0) {
      printf("book index: %d\n", i);
      printBookInfo(&booksArray[i]);
      isFind = 1;
    }
  }

  if (isFind)
    return;
  else {
    printf("%s is not found!!\n\n", publisher);
  }
}
void borrowBook(Book booksArray[]) {
  printf("Enter the title of the book you want to borrow: ");
  char title[100] = {0};
  scanf("%s", title);
  int isFind = 0;
  for (int i = 0; booksArray[i].title[0] != 0; i++) {
    if (strcmp(booksArray[i].title, title) == 0) {
      if (booksArray[i].isBorrowed == 0) {
        printf("Borrow success!\n");
        booksArray[i].isBorrowed = 1;
        isFind = 1;
      } else {
        printf("That book is already borrowed. Sorry.\n");
      }
    }
  }
  if (!isFind)
    printf("That book is not found.\n\n");
}
void returnBook(Book booksArray[]) {
  printf("Enter the title of the book you want to return: ");
  char title[100] = {0};
  scanf("%s", title);
  int isFind = 0;

  for (int i = 0; booksArray[i].title[0] != 0; i++) {
    if (strcmp(booksArray[i].title, title) == 0) {
      if (booksArray[i].isBorrowed == 1) {
        printf("Return success!\n");
        booksArray[i].isBorrowed = 0;
        isFind = 1;

      } else {
        printf("That book is already returned. Sorry.\n");
      }
    }
  }
  if (!isFind)
    printf("That book is not found.\n\n");
}
void showInvalidInput() { printf("Invalid input. Try again!\n\n"); }
