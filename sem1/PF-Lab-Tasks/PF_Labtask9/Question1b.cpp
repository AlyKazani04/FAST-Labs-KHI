#include <stdio.h>
int main(){
	int rows, var=1;
	printf("Enter num of rows ");
	scanf("%d",&rows);
	for(int i = 1; i<rows+1;i++){
		for(int j =1;j<=i;j++){
			printf("%d",j);
			var++;
		}
		if(i>1){
			for(int j =var-1;j>=1;j--){
				printf("%d",j);
			}
		}
		printf("\n");
		var=0;
	}
}
