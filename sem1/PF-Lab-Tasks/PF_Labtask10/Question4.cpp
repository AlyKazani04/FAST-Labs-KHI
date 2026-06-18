#include <stdio.h>
#include <string.h>
typedef struct TravelPackage{
	char name[100];
	char destination[100];
	int durdays;
	float cost;
	int seats;
};
void addPackages(TravelPackage package[], int num){
	for(int i = 0; i < num; i++){
		printf("Enter Package %d Name: ", i + 1);
		scanf(" %[^\n]", package[i].name);
		printf("Enter Package %d Destination: ", i + 1);
		scanf(" %[^\n]", package[i].destination);
		printf("Enter Package %d Duration (in days): ", i + 1);
		scanf("%d", &package[i].durdays);
		printf("Enter Package %d Cost: ", i + 1);
		scanf("%f", &package[i].cost);
		printf("Enter Package %d Number of Seats Available: ", i + 1);
		scanf("%d", &package[i].seats);
		printf("\n");
	}
	printf("_________________________\n\n");
}
void displayPackages(TravelPackage package[], int num){
	if(num == 0){
		printf("No Packages Available\n");
		printf("_________________________\n\n");
		return;
	}
	for(int i = 0; i < num; i++){
		printf("Package %d Name: %s\n", i + 1, package[i].name);
		printf("Destination: %s\n", package[i].destination);
		printf("Duration: %d days\n", package[i].durdays);
		printf("Cost: $%.2f\n", package[i].cost);
		printf("Seats Available: %d\n", package[i].seats);
		printf("_________________________\n\n");
	}
}
void bookPackage(TravelPackage package[], int num){
	char name[100];
	int found = 0;
	printf("Enter the Package Name to book: ");
	scanf("%[^\n]", name);
	for(int i = 0; i < num; i++){
		if(strcmp(package[i].name, name) == 0){
			found = 1;
			if(package[i].seats > 0){
				package[i].seats--;
				printf("Package \"%s\" successfully booked!\n", package[i].name);
				printf("Remaining seats: %d\n", package[i].seats);
				printf("_________________________\n\n");
			} 
			else{
				printf("Sorry, \"%s\" is fully booked.\n", package[i].name);
				printf("_________________________\n\n");
			}
			break;
		}
	}
	if(!found){
		printf("Package \"%s\" not found.\n", name);
		printf("_________________________\n\n");
	}
}
int main(){
	TravelPackage package[100];
	int num = 0, n;
	while(1){
		printf("Enter 1 to Add Packages, 2 to Display Packages, 3 to Book a Package, 0 to End: ");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("Enter the number of packages you would like to add: ");
				int addNum;
				scanf("%d", &addNum);
				printf("_________________________\n\n");
				addPackages(package + num, addNum);
				num += addNum;
				break;
			case 2:
				printf("Available Packages:\n");
				displayPackages(package, num);
				break;
			case 3:
				bookPackage(package, num);
				break;
			case 0:
				printf("Exiting the program.\n");
				return 0;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}
}
