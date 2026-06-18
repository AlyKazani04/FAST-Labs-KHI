#include <stdio.h>
int main(){
	int n;
	printf("Enter a num\n");
	scanf("%d",&n);
	if (n<1){
		printf("number is negative");
	}
	else{
		n-=1;
		while (n>1){
			if(n%2==0){
				printf("%d\n",n);
				n-=1;
			}
			else{
				n-=1;
			}
		}
	}
}