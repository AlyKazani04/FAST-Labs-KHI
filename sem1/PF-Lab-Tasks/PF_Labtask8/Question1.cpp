#include <stdio.h>
int main(){
	int inarr[3][3], rowsum, colsum[3] = {0, 0, 0};
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++){
			printf("Enter number for row %d, column %d: ",i+1,j+1);
			scanf("%d", &inarr[i][j]);
		}
	}
	for(int i = 0; i < 3; i++) {
		rowsum = 0;
		for (int j = 0; j < 3; j++){
			rowsum += inarr[i][j];
			switch(j){
				case 0:
					colsum[0] += inarr[i][j];
					break;
				case 1:
					colsum[1] += inarr[i][j];
					break;
				case 2:
					colsum[2] += inarr[i][j];
					break;
			}
		}
		printf("Rowsum %d = %d\n", i+1, rowsum);
	}
	for(int i =0 ; i<3; i++){
		printf("Colsum %d = %d\n", i+1 ,colsum[i]);
	}
}
