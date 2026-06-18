#include "library.h"
#include <stdio.h>

Book library[MAX_BOOKS];
int bookCount;

void addBook() {
  if (bookCount >= MAX_BOOKS) {
    printf("Library is full.\n");
    return;
  }

  printf("Enter Book ID: ");
  scanf("%d", &library[bookCount].id);

  printf("Enter Book Name: ");
  scanf(" %[^\n]", library[bookCount].name);

  library[bookCount].isIssued = 0;
  bookCount++;

  printf("Book Added!\n");
}
