#include "library.h"
#include <stdio.h>

int main() {
  int choice;

  while (1) {
    printf("Library System\n");
    printf("1. Add Book\n");
    printf("2. Issue Book\n");
    printf("0. Exit\n");

    printf("Enter: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addBook();
      break;
    case 2:
      issueBook();
      break;
    case 0:
      printf("Exiting...\n");
      return 0;
    default:
      printf("Invalid Choice. Try Again.\n");
    }
  }

  return 1;
}
