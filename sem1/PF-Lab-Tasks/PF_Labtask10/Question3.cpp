#include <stdio.h>
#include <string.h>
typedef struct cars{
		char make[100];
		char model[100];
		int year;
		int price;
		float mileage;
};
void addCars(cars car[], int num){
	for(int i = 0; i<num ; i++){
		printf("Enter Car %d Make : ", i+1);
		scanf("%s", &car[i].make);
		printf("Enter Car %d model : ", i+1);
		scanf("%s", &car[i].model);
		printf("Enter Car %d Manufacturing Year : ", i+1);
		scanf("%d", &car[i].year);
		printf("Enter Car %d Price : ", i+1);
		scanf("%d", &car[i].price);
		printf("Enter Car %d Mileage : ", i+1);
		scanf("%f", &car[i].mileage);
	}
	printf("_________________________\n\n");
}
void displayCars(cars car[], int num){
	if(num==0){
		printf("No Cars Available");
		printf("_________________________\n\n");
		return;
	}
	for(int i= 0; i<num; i++){
		printf("Car %d Make = %s\n", i+1, car[i].make);
		printf("Car %d Model = %s\n", i+1, car[i].model);
		printf("Car %d Manufacturing Year = %d\n", i+1, car[i].year);
		printf("Car %d Price = %d\n", i+1, car[i].price);
		printf("Car %d Mileage = %.2f\n", i+1, car[i].mileage);
		printf("\n");
	}
	printf("_________________________\n\n");
	return;
}
void searchCarsMake(cars car[], char arr[], int num){
	int found = 0;
	for(int i = 0; i<num ; i++){
		if(strcmp(car[i].make, arr)==0){
			printf("Car %d Make = %s\n", i+1, car[i].make);
			printf("Car %d Model = %s\n", i+1, car[i].model);
			printf("Car %d Manufacturing Year = %d\n", i+1, car[i].year);
			printf("Car %d Price = %d\n", i+1, car[i].price);
			printf("Car %d Mileage = %.2f\n", i+1, car[i].mileage);
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
void searchCarsModel(cars car[], char arr[], int num){
	int found = 0;
	for(int i = 0; i<num ; i++){
		if(strcmp(car[i].model, arr)==0){
			printf("Car %d Make = %s\n", i+1, car[i].make);
			printf("Car %d Model = %s\n", i+1, car[i].model);
			printf("Car %d Manufacturing Year = %d\n", i+1, car[i].year);
			printf("Car %d Price = %d\n", i+1, car[i].price);
			printf("Car %d Mileage = %.2f\n", i+1, car[i].mileage);
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
int main(){
	cars car[100];
	int num=0, n, search;
	char arr[100];
	while(1){
		printf("Enter 1 to Add Cars, 2 to Display Cars, 3 to Search for Cars and 0 to End : ");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("Enter the number of cars you would like to add : ");
				scanf("%d", &num);
				addCars(car, num);
				break;
			case 2:
				printf("Cars available :\n");
				displayCars(car, num);
				break;
			case 3:
				printf("Search by Make(Enter 1) or Model(Enter 2) or Enter 0 to Cancel :");
				scanf("%d", &search);
				if(search==1){
					printf("Enter Make:");
					scanf("%s", &arr);
					searchCarsMake(car, arr, num);
				}
				else if(search==2){
					printf("Enter Model:");
					scanf("%s", &arr);
					searchCarsModel(car, arr, num);
				}
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
