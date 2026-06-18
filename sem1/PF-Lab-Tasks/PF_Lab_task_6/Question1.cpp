#include <stdio.h>
int main(){
	int total, i,num;
	printf("enter a number\n");
	scanf("%d", &num);
	if (num<0){
		printf("Input is less than zero factorial is not possible.");
	}
	else{
	total=1;
	for(int i=1; i<=num;i++){
		total = total * i;
	}
	printf("Factorial is: %d",total);
	}
}