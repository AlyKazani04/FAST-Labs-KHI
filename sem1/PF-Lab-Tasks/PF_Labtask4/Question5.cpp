#include <stdio.h>
int main(){
	int hour;
	printf("insert hour of day in 24 hour clock format\n");
	scanf("%d", &hour);
	if (hour>=0 && hour<=5){
		printf("Good Night\n");
	}
	else if (hour>=6 && hour<=11){
		printf("Good Morning\n");
	}
	else if (hour>=12 && hour<=17){
		printf("Good Afternoon\n");
	}
	else if (hour>=18 && hour<=23){
		printf("Good Evening");
	}
	else{
		printf("Invalid Time");
	}
}
