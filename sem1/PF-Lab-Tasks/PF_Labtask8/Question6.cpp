#include <stdio.h>
int main(){
	int l;
	printf("Enter the length of the squares side: ");
	scanf("%d", &l);
	for(int i = 0; i < l ; i++){
		for(int j = 0; j < l ; j++){
			if(i==0 || i==l-1 || j==0 || j==l-1 || i==j || j==l-i-1){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

