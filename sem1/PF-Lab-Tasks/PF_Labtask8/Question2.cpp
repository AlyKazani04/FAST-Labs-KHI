#include <stdio.h>
int main(){
	int inarr[4][4];
	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++){
			printf("Enter grade for student %d, subject %d: ",i+1,j+1);
			scanf("%d", &inarr[i][j]);
		}
	}
	printf("Before updating\n");
	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++){
			printf(" %d ",inarr[i][j]);
		}
		printf("\n");
	}
	for(int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if(inarr[i][j] <0){
				inarr[i][j] = 0;
			}
		}
	}
	printf("After updating\n");
	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++){
			printf(" %d ",inarr[i][j]);
		}
		printf("\n");
	}
}
