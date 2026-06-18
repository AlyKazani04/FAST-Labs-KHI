#include <stdio.h>
int main(){
	int bolt = 5, nut = 3, washer = 1, nbolt, nnut, nwash;
	printf("Number of bolts: \t");
	scanf("%d", &nbolt);
	printf("Number of nuts: \t");
	scanf("%d", &nnut);
	printf("Number of washers: \t");
	scanf("%d", &nwash);
	int cost = bolt*nbolt + nut*nnut + washer*nwash;
	
	
	printf("\nCheck the order: \t");
	if(nnut>=nbolt && nwash>=(2*nbolt)){
		printf("Order is OK");
	}
	else{
		if(nnut<nbolt){
			printf("too few nuts");
		}
		if(nwash<(2*nbolt)){
			printf("too few washers");
		}
	}
	printf("\nTotal cost: \t\t%d",cost);
}
