#include <stdio.h>
int main(){
	int scores[4][4], temp;
	
	for(int i = 0; i < 4 ; i++){
		for(int j = 0; j < 4 ; j++){
			printf("Enter a score for round %d, team %d: ", i+1 , j+1);
			scanf("%d", &scores[i][j]);
		}
	}
	
	printf("Scores before sort\n");
	for(int i = 0; i < 4 ; i++){
		for(int j = 0; j < 4 ; j++){
			printf(" %d ", scores[i][j]);
		}
		printf("\n");
	}
	
	for(int j = 0 ; j < 4 ; j++){
		for(int i = 0 ; i < 3 ; i++ ){
			for(int k = 0 ; k < 3 - i ; k++ ){
				if(scores[k][j] > scores[k + 1][j]){
					temp = scores[k][j];
					scores[k][j] = scores[k + 1][j];
					scores[k + 1][j] = temp;
				}
			}
		}
	}
	
	printf("Scores after sort\n");
	for(int i = 0; i < 4 ; i++){
		for(int j = 0; j < 4 ; j++){
			printf(" %d ", scores[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

