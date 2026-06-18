#include <stdio.h>
int main(){
	int num;
	do{
	printf("enter a positive number:");
	scanf("%d",&num);
	if(num<=0){
	printf("Not it, buddy...\n");
	}
	else{
		printf("Now that's a positive number!\n");
	}
	}while(num<=0);
}