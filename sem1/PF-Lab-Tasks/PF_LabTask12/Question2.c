#include <stdio.h>
#include <stdlib.h>
int minusone(int *arr,int n){
	int i;
	for(i = 0 ; i < n; i++){
		if( *(arr+i)%2 != 0){
			*(arr+i) -= 1;
		}
	}
}
int main(){
	int n, i;
	printf("Enter number of values : ");
	scanf("%d", &n);
	int *arr = (int *)malloc(n*sizeof(int));
	int var = 0;
	for(i = 0 ; i < n; i++){
		printf("Value %d: ", i+1);
		scanf("%d", &var);
		arr[i] = var;
		var = 0;
	}
	printf("Array Before :\n");
	for(i = 0 ; i < n; i++){
		printf(" %d", arr[i]);
	}
	printf("\n");
	minusone(arr, n);
	printf("Array After :\n");
	for(i = 0 ; i < n; i++){
		printf(" %d", arr[i]);
	}
	free(arr);
	return 0;
}
