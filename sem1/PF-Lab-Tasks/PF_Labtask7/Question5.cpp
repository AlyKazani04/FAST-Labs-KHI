#include <stdio.h>
int main(){
	int i,size=20;
	int arr[size];
	for (i=0;i<size;i++){
		printf("input number(%d): ",i+1);
		scanf("%d", &arr[i]);
	}
	for (i=size-1;i>-1;i--){
		printf("%d ", arr[i]);
	}
}
