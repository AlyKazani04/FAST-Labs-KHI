#include <stdio.h>
int main(){
	int m, n;
	
	printf("Enter m for a matrix(m x n) : ");
	scanf("%d", &m);
	printf("Enter n for a matrix(m x n) : ");
	scanf("%d", &n);
	
	int mat1[m][n], mat2[m][n], summat[m][n];
	
	printf("Matrix 1:\n");
	for(int i = 0; i < m ; i++){
		for(int j = 0; j < n ; j++){
			printf("Enter a number for row %d,column %d: ", i+1 , j+1);
			scanf("%d", &mat1[i][j]);
		}
	}
	
	printf("Matrix 2:\n");
	for(int i = 0; i < m ; i++){
		for(int j = 0; j < n ; j++){
			printf("Enter a number for row %d,column %d: ", i+1 , j+1);
			scanf("%d", &mat2[i][j]);
		}
	}
	printf("Sum:\n");
	for(int i = 0; i < m ; i++){
		for(int j = 0; j < n ; j++){
			summat[i][j] = mat1[i][j] + mat2[i][j];
			printf(" %d ", summat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

