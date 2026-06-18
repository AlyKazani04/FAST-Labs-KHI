#include <stdio.h>
void percentages(float val, int count){
	if(count>100){
		return;
	}
	printf("%d percent = %.1f\n", count, val*((float)count/100));
	percentages(val, count+1);
}
int main(){
	int num;
	printf("enter a number: ");
	scanf("%d", &num);	
	
	percentages(num, 1);
	return 0;
}
