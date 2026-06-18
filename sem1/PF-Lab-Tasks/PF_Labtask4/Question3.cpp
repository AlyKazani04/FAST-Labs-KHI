#include <stdio.h>
int main(){
	float cost;
	float discount;
	float amountsaved;
	float bill;
	printf("enter cost of shopping\n");
	scanf("%f", &cost);
	if (cost>5000){
		discount = 0.3;
	}
	else if (cost>3000 && cost<=5000){
		discount = 0.22;
	}
	else if (cost>1500 && cost<=3000){
		discount = 0.12;
	}
	else if (cost>0 && cost<=1500){
		discount = 0.07;
	}
	amountsaved = cost * discount;
	bill = cost - amountsaved;
	printf("cost was: %.2f\n", cost);
	printf("amount saved from discount: %.2f\n", amountsaved);
	printf("amount after discount: %.2f", bill);
}
