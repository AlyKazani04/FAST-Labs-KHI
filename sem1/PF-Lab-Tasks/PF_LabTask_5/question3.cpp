#include <stdio.h>
int main(){
	float score;
	printf("Enter your score as percentage: ");
	scanf("%f", &score);
	(score>=90) ? printf("grade=A"):
		(score>=80 && score<90) ? printf("grade=B"):
			(score>=70 && score<80) ? printf("grade=C"):
				(score>=60 && score<70) ? printf("grade=D"): 
					printf("grade=F");;;;;
	
	
	
	
}