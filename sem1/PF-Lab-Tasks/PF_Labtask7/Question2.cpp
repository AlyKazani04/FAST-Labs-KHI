#include <stdio.h>
int main(){
	int arr[10], num, index1;
	for(int i=0;i<10;i++){
		printf("Enter a number: ");
		scanf(" %d", &num);
		arr[i] = num;
	}
	printf("Input array: { ");
    for(int i = 0; i < 10; i++) {
        printf("%d", arr[i]);
        if(i < 9) {
            printf(", ");
        }
    }
    printf(" }\n");
    index1 = arr[0];
    for(int i = 0; i < 9; i++){
    	arr[i] = arr[i+1];
	}
	arr[9] = index1;
	printf("Array Shifted One Left: { ");
    for(int i = 0; i < 10; i++) {
        printf("%d", arr[i]);
        if(i < 9) {
            printf(", ");
        }
    }
    printf(" }\n");
}
