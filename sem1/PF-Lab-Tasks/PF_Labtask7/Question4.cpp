#include <stdio.h>
int main(){
	int i,size=15,sum=0;
	int arr[size];
	for (i=0;i<size;i++){
		printf("input number(%d) : ",i+1);
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("%d",sum);
}
