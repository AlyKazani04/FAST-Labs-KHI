#pragma once

#define MAX_BOOKS 100

typedef struct {
  int id;
  char name[100];
  int isIssued;
} Book;

extern Book library[MAX_BOOKS];
extern int bookCount;
void addBook();
void issueBook();
