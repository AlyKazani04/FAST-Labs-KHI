#include <stdio.h> 
int main(){
	int x;
	int y;
	printf("enter the first number");
	scanf("%d", &x);
	printf("enter the second number"); 
	scanf("%d", &y);
	if (x==y){
		printf("x is equal");
	}
	else{
		if (x>y){
			if (x>=y+100){
				printf("first number is significantly greater");
			}
			else {
				printf("first number is greater");
			}
		}
		else {
			if (x<0) {
				printf("first number is negative and smaller");
			}
			else{
				printf("first number is smaller");
			}
		}
	}
}
