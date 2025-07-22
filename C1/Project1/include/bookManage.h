// bookManage.h
#ifndef BOOKMANAGE_H
#define BOOKMANAGE_H
typedef struct {
  int isBookExist;
  int bookIndex;
  char title[100];
  char author[100];
  char publisher[100];
  int borrowed;
} Book;
void bookManageProgram();
void showOptions();
int inputOptionNum();
void showExitProgram();
void registerBook(Book bookArray[]);
void searchBook(Book bookArray[]);
void printBookInfo(const Book *book);
void searchBookByTitle(Book bookArray[]);
void searchBookByAuthor(Book bookArray[]);
void searchBookByPublisher(Book bookArray[]);
void borrowBook(Book bookArray[]);
void returnBook(Book bookArray[]);
void showInvalidInput();
#endif