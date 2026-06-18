#include <stdio.h>

int main(){
	int rows,rnum=1;
	printf("Enter number of rows");
	scanf("%d",&rows);
	for(int i=rows+1;i>1;i--){
		for(int j=i;j>0;j--){
			printf(". ");
		}
		for(int j=0;j<rnum;j++){
			printf("o");
		}
		printf("\n");
		rnum++;
	}
	for(int i=1;i<rows+2;i++){
		for(int j=0;j<i;j++){
			printf(". ");
		}
		for(int j=0;j<rnum;j++){
			printf("o");
		}
		printf("\n");
		rnum--;
	}
	
}
