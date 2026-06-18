#include <stdio.h>
#include <stdlib.h>

void insertInArray(int **arr, int *size, int pos, int val){
	int i;
    (*size)++;
    *arr = (int*)realloc(*arr, (*size)*sizeof(int));
    if(*arr == NULL){
        printf("Realloc failed.\n");
        exit(1);
    }
    for( i = *size - 1; i > pos; i--){
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[pos] = val;
}

void deleteFromArray(int **arr, int *size, int pos){
    int i;
    for( i = pos-1 ; i < *size - 1 ; i++){
        (*arr)[i] = (*arr)[i + 1]; // Shift elements left
    }
    (*size)--; // Decrease size
    *arr = (int *)realloc(*arr, (*size) * sizeof(int)); // Resize array
    if(*arr == NULL && *size > 0){
        printf("Realloc failed.\n");
        exit(1);
    }
}

int main(){
	int T, N, X, P, i, j;
	char temp[100];
//	printf("test cases: ");
	scanf("%d", &T);
	while(T--){
//		printf("Initial array size: ");
		scanf("%d", &N);
		int *arr = (int *)malloc(N*sizeof(int));
		if(arr == NULL){
			printf("malloc failed.\n");
			exit(1);
		}
		for( j = 0 ; j < N ; j++ ){
			scanf("%d", &arr[j]);
		}
		getchar();
		while(1){
			if(fgets(temp, sizeof(temp), stdin) == NULL || strcmp(temp, "\n") == 0){
				break;
			}
		//	processing
			char ch;
			int valsread = sscanf(temp, "%c %d %d", &ch, &X, &P);
			if(ch == 'I' && valsread == 3){
				if (P < 0 || P > N+1) {
					printf("Invalid position for insertion.\n");
				}
				else{
					insertInArray(&arr, &N, P-1, X);
				}
			} 
			else if(ch == 'D' && valsread == 2){
				if (P <= 0 || P > N) {
					printf("Invalid position for deletion.\n");
				}
				else{
					deleteFromArray(&arr, &N, P-1);
				}
			}
			else{
				printf("Invalid operation or arguments.\n");
			}
		}
	//	output
		for( i = 0 ; i < N ; i++ ){
			printf("%d ", arr[i]);
		}
		printf("\n");
		free(arr);
	}
	return 0;
}

