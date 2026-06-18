#include <stdio.h>
main(){
	int units;
	float charges;
	float bill;
	printf("input electricity units\n");
	scanf("%d", &units);
	if (units<=30 ){
		charges = 0.60;
	}
	else if(units>30 && units<=110){
		charges = 0.85;
	}
	else if(units>110 && units<=210){
		charges = 1.30;
	}
	else if(units>210){
		charges = 1.60;
	}
	bill = units * charges;
	bill = bill * 1.15;
	printf("bill is %.2f", bill);
}
