#include <stdio.h>
int main(){
	int num ,total;
	do{
	printf("enter a number to add or zero to end:\n");
	scanf("%d",&num);
	total += num;
	printf("total is %d\n", total);
	}while(num!=0);
}