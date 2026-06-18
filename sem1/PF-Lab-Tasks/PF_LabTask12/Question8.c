#include <stdio.h>
#include <stdlib.h>
void pointprofits(float *arr, int size){
	int i;
	float total = 0;
	for( i = 0 ; i < size ; i++ ){
		printf("Enter fee for point %d: ", i+1);
		scanf("%f", &arr[i]);
		total += (arr)[i];
	}
	printf("Total ");
	(total >= 0) ? printf("Profit ") : printf("Loss ");
	printf("for the Facility is: %.2f.\n", total);
}
int main(){
	int num;
	printf("Number of points in facility: ");
	scanf("%d", &num);
	float *arr = (float *)malloc(num*sizeof(float));
	if(arr == NULL){
		printf("Malloc Failed.\n");
		return 1;
	}
	pointprofits(arr, num);
	free(arr);
	printf("freed memory.\n");
	return 0;
}
