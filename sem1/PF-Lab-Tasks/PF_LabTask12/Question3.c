#include <stdio.h>
#include <stdlib.h>
void addnumber(float **arr, int *size, float number,int *count){
	if(*count == *size){
		*size *= 2;
		*arr = (float *)realloc(*arr,(*size)*sizeof(float));
		if(*arr == NULL){
			printf("Reallocation failed.\n");
			exit(0);
		}
	}
	(*arr)[*count] = number;
	(*count)++;
	printf("Added.\n");
}
void displayarr(float *arr,int count){
	int i;
	printf("Array : [");
	for( i = 0 ; i < count ; i++){
		printf(" %.2f", arr[i]);
		if(i != count-1){
			printf(",");
		}
	}
	printf(" ]\n");
}
void removelast(float *arr, int *count){
	int i;
	if(*count==0){
		printf("Array is empty.\n");
		return;
	}
	(*count)--;
	printf("Last removed.\n");
}
int main(){
	int size = 4, count = 0, num;
	float number;
	float *arr = (float *)malloc(size * sizeof(float));
	if(arr == NULL){
		printf("Allocation failed.\n");
		return 0;
	}
	while(1){
		printf("\n1. Add a float to the Array\n");
		printf("2. Display Array\n");
		printf("3. Remove Last number from the Array\n");
		printf("4. Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &num);
		switch(num){
			case 1: 
				printf("Value to enter : ");
				scanf("%f", &number);
				addnumber(&arr, &size, number, &count);
				break;
			case 2:
				displayarr(arr, count);
				break;
			case 3:
				removelast(arr, &count);
				break;
			case 4:
				printf("Exiting...\n");
				free(arr);
				return 0;
			default:
				printf("Invalid input Try Again.\n");
		}
	}
	free(arr);
	return 0;
}
