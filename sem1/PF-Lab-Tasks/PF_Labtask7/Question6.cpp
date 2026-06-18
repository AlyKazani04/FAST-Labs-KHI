#include <stdio.h>
int main(){
	int max,min,i=0,size=30;
	int arr[size];
	for (i=0;i<size;i++){
		printf("input number(%d): ",i+1);
		scanf("%d", &arr[i]);
	}
	max=arr[0];
	min=arr[0];
	for(i=1;i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}	
	printf("Max number is: %d\n",max);
	printf("Min number is: %d\n",min);
}
