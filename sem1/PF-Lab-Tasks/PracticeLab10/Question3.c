#include <stdio.h>
#include <string.h>
typedef struct Book{
		char title[50];
		char author[50];
		int isbn;
		int publication_year;
		int isAvailable;
}Book;
void addBook(Book book[], int *num, int addcount){
	int i;
	for( i = *num; i < *num + addcount ; i++){
		printf("Enter Book %d Title : ", i+1);
		scanf(" %49[^\n]%*c", book[i].title);
		printf("Enter Book %d Author : ", i+1);
		scanf(" %49[^\n]%*c", book[i].author);
		printf("Enter Book %d isbn : ", i+1);
		scanf("%d", &book[i].isbn);
		getchar();
		printf("Enter Book %d publication year : ", i+1);
		scanf("%d", &book[i].publication_year);
		getchar();
		while(1){
			printf("Enter Book %d Availability(1 for Available, 0 for Not Available): ", i+1);
			scanf("%d", &book[i].isAvailable);
			if(book[i].isAvailable==0 || book[i].isAvailable==1){
				break;
			}
			else{
				printf("Invalid Availability, try again.\n");
			}
		}
	}
	*num += addcount;
	printf("_________________________\n\n");
}

void searchBookTitle(Book book[], char arr[], int *num){
	int found = 0, i;
	for( i = 0; i<*num ; i++){
		if(strcmp(book[i].title, arr)==0){
			printf("Book %d Title= %s\n", i+1, book[i].title);
			printf("Book %d Author = %s\n", i+1, book[i].author);
			printf("Book %d ISBN = %d\n", i+1, book[i].isbn);
			printf("Book %d Publication Year = %d\n", i+1, book[i].publication_year);
			if(book[i].isAvailable==1){
				printf("Availability: Available\n");
			}
			else{
				printf("Availability: Not Available\n");
			}
			printf("\n");
			found = 1;
		}
	}
	if(!found){
		printf("Did Not Find %s\n", arr);
	}
	printf("_________________________\n\n");
	return;
}

void searchBookAuthor(Book book[], char arr[], int *num){
	int found = 0, i;
	for(i = 0; i<*num ; i++){
		if(strcmp(book[i].author, arr)==0){
			printf("Book %d Title = %s\n", i+1, book[i].title);
			printf("Book %d Author = %s\n", i+1, book[i].author);
			printf("Book %d ISBN = %d\n", i+1, book[i].isbn);
			printf("Book %d Publication Year = %d\n", i+1, book[i].publication_year);
			if(book[i].isAvailable==1){
				printf("Availability: Available\n");
			}
			else{
				printf("Availability: Not Available\n");
			}
			printf("\n");
			found = 1;
		}
	}
	if(!found){
		printf("Did Not Find %s\n", arr);
	}
	printf("_________________________\n\n");
	return;
}
void checkout(Book book[], char arr[], int *num){
	int found = 0, i;
	for(i = 0; i<*num ; i++){
		if(strcmp(book[i].title, arr)==0){
			if(book[i].isAvailable==1){
				book[i].isAvailable = 0;
				printf("Checked Out.\n");
			}
			else{
				printf("This Book Cannot be Checked Out.\n");
			}
			found = 1;
		}
	}
	if(!found){
		printf("Did Not Find %s\n", arr);
	}
	printf("_________________________\n\n");
	return;
}
void returnBook(Book book[], char arr[], int *num){
	int found = 0, i;
	for(i = 0; i<*num ; i++){
		if(strcmp(book[i].title, arr)==0){
			if(book[i].isAvailable==0){
				book[i].isAvailable = 1;
				found = 1;
				printf("Returned.\n");
			}
			else{
				printf("This Book Cannot be Returned.\n");
			}
			break;
		}
	}
	if(!found){
		printf("Did Not Find %s\n", arr);
	}
	printf("_________________________\n\n");
	return;
}

int main(){
	Book book[100] = {0};
	int num = 0, n, addcount, search;
	char arr[100];
	while(1){
		printf("Enter 1 to Add a Book, 2 to Search for a book, 3 to Checkout a book, 4 to Return a book or 0 to End : ");
		if (scanf("%d", &n) != 1) {
        	printf("Invalid input. Please enter a number.\n");
        	while (getchar() != '\n');
        	continue;
		}
		switch(n){
			case 1:
				printf("Enter the number of Books you would like to add : ");
				scanf("%d%*c", &addcount);
				printf("\n");
				addBook(book, &num, addcount);
				break;
			case 2:
				printf("Search by Title(Enter 1) or Author(Enter 2) or Enter 0 to Cancel: ");
				if (scanf("%d", &search) != 1 || (search != 1 && search != 2 && search != 0)) {
					printf("Invalid input. Try again.\n");
					while (getchar() != '\n'); // Clear buffer
					break;
				}
				if (search == 0) {
					break;
				}
				printf("Enter %s: ", (search == 1) ? "Title" : "Author");
				getchar();
				fgets(arr, sizeof(arr), stdin);
				arr[strcspn(arr, "\n")] = '\0';
				if(strlen(arr) == 0){
					printf("Input cannot be empty. Try again.\n");
					break;
				}
				if(search == 1){
					searchBookTitle(book, arr, &num);
				}
				else{
					searchBookAuthor(book, arr, &num);
				}
				break;
			case 3:
				printf("Enter the Title of the Book you want to Checkout : ");
				scanf(" %49[^\n]%*c", arr);
				checkout(book, arr, &num);
				break;
			case 4:
				printf("Enter the Title of the Book you want to Return : ");
				scanf(" %49[^\n]%*c", arr);
				returnBook(book, arr, &num);
				break;
			case 0:
				printf("Operation Ended.\n");
				return 0;
			default:
				printf("Invalid Entry Try Again\n");
		}
	}
	return 0;
}
