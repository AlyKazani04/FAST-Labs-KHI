#include <stdio.h>
int main(){
	int num,j;
	printf("enter a num:");
	scanf("%d", &num);
		
	for(int i = num; i > 0; i-- ){
		for(j=1;j<=num-i;j++){
			printf(" ");
		}
		for(j=0;j<=i-1;j++){
			printf("%d ",i-j);
		}
		if(i!=0){
			printf("\n");
		}
	}
	
	for(int i = 2; i <= num; i++ ){
		for(j=1;j<=num-i;j++){
			printf(" ");
		}
		for(j = 0 ; j <= i-1 ; j++){
			printf("%d ",i-j);
		}
		if(i!=0){
			printf("\n");
		}
	}
}
