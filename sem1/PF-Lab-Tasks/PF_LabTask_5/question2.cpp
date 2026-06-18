#include <stdio.h>
int main(){
	int a, b, c, t;
	printf("Input the 3 angles:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	t = a + b + c;
	if (a>0 && b>0 && c>0){
		if (t == 180){
			printf("valid triangle");
		}
		else{
			printf("invalid triangle");
		}
	}
	else{
		printf("invalid triangle");
	}
}