#include <stdio.h>
int main(){
	char member;
	float cost;
	printf("enter whether customer is member or not(Y=yes,N=no): \n");
	scanf("%c", &member);
	printf("enter cost:\n");
	scanf("%f", &cost);
	(cost > 100 && (member=='Y' || member == 'y')) ? 
		printf("Discount is applicable"): 
		printf("Discount is not applicable");
}