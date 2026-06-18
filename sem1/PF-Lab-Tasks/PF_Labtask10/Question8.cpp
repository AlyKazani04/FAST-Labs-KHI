#include <stdio.h>
void recursivePrint(int arr[], int size){
	if(size == -1){
		return;
	}
	recursivePrint(arr, size-1);
	printf("%d ", arr[size]);
}
int main(){
	printf("Array:\n");
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	recursivePrint(arr, size-1);	
	return 0;
}

