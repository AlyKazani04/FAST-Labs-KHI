#include <stdio.h>
void recursiveBubbleSort(int arr[], int size){
	int temp;
	if(size==1){
		return;
	}
	for(int i = 0; i<size-1 ; i++){
		if(arr[i]>arr[i+1]){
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	recursiveBubbleSort(arr, size-1);
}
int main(){
	int arr[]={2,6,4,2,233,688,985,23,21,2,0,21,56};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Before sorting:\n");
	for(int i = 0; i<size; i++){
	    printf("%d ", arr[i]);
	}
	printf("\n");   
	
	recursiveBubbleSort(arr, size);
	
	printf("After sorting:\n");
	for(int i = 0; i<size; i++){
	    printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
