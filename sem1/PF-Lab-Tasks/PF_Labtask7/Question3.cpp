#include <stdio.h>
int main(){
	int inarr[12], num, index1;
	int outarr[6];
	for(int i=0;i<12;i++){
		printf("Enter a number: ");
		scanf(" %d", &num);
		inarr[i] = num;
	}
	printf("Input array: { ");
    for(int i = 0; i < 12; i++){
        printf("%d", inarr[i]);
        if(i < 11) {
            printf(", ");
        }
    }
    printf(" }\n");
	for(int i=0;i<12;i+=2){
		outarr[i/2]=inarr[i] + inarr[i+1];
	}
	printf("Array Pair Sums Array: { ");
    for(int i = 0; i < 6; i++) {
        printf("%d", outarr[i]);
        if(i < 5) {
            printf(", ");
        }
    }
    printf(" }\n");
}
