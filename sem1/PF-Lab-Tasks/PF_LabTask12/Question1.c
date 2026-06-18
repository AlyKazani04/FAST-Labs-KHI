#include <stdio.h>
#include <stdlib.h>
int main(){
	int stdnum, grdnum[stdnum], i, j;
	printf("Enter number of students : ");
	scanf(" %d", &stdnum);
	int **students = (int **)malloc(stdnum*sizeof(int*));
	if(students == NULL){
		printf("didnt not alloc");
	}
	for( i=0; i<stdnum;i++){
		students[i] = (int *)malloc(grdnum[i]*sizeof(int));
		if(students[i] == NULL){
			printf("didnt not alloc");
		}
	}
	int var;
	for( i=0; i<stdnum;i++){
		printf("Enter number of grades for Student %d : ", i+1);
		scanf("%d", &grdnum[i]);
		printf("Enter grades for Student %d : \n", i+1);
		for( j=0; j<grdnum[i];j++){
			printf("\tGrade %d: ", j+1);
			scanf(" %d", &var);
			students[i][j] = var;
			var = 0;
		}
	}
	printf("Grades: \n");
	for( i=0; i<stdnum;i++){
		printf("Student %d : \n", i+1);
		printf("\tGrade : ");
		for( j=0; j<grdnum[i];j++){
			printf("%d ", students[i][j]);
		}
		printf("\n");
	}
	for( i=0; i<stdnum;i++){
		for( j=0; j<grdnum[i];j++){
			free((students+j));	
		}
	}
	free(students);
	return 0;
}
