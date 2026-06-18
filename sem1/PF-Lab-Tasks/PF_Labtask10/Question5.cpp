#include <stdio.h>
int digitSum(int num){
	if(num == 0){
		return 0;
	}
	int result =  num%10 + digitSum(num/10);
	return result;
}
int main(){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("%d",digitSum(num));
	return 0;
}

