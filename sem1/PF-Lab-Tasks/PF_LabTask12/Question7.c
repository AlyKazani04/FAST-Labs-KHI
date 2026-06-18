#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void initialize(int ***arr, int *size, int row, int col){
    *arr = (int**)malloc(row*sizeof(int *));
    if(arr == NULL){
        printf("Memory not allocated.\n");
        return;
    }
    int i, j;
    for( i = 0 ; i < row ; i++ ){
        (*arr)[i] = (int *)calloc(col, sizeof(int));
        if((*arr)[i] == NULL){
            printf("Memory allocation failed for row %d\n", i);
            return;
        }
        for( j = 0 ; j < col ; j++){
            (*arr)[i][j] = rand()%10; 
        }
    }
}
void printarr(int **arr, int row){
	int i, j;
    for( i = 0 ; i < row ; i++ ){
        for( j = 0 ; j < row ; j++ ){
            printf("%d ", (arr)[i][j]);
        }
        printf("\n");
    }
}
void insertdelete(int **arr, int row, int col, int rowpos, int colpos, int value){
    char n;
    printf("Do you want to insert or delete? (i/d): ");
    scanf(" %c", &n);
	n = tolower(n);
    if(n == 'i'){
        if(rowpos >= 0 && rowpos < row && colpos >= 0 && colpos < col){
            arr[rowpos][colpos] = value;
            printf("Inserting %d at (row:%d, col:%d).", value, rowpos+1, colpos+1	);
        } 
		else{
            printf("Invalid position for insertion.\n");
        }
    }
	else if(n == 'd'){
        if(rowpos >= 0 && rowpos < row && colpos >= 0 && colpos < col){
            arr[rowpos][colpos] = 0;
        }
		else{
            printf("Invalid position for deletion.\n");
        }
    }
	else{
        printf("Invalid. Please enter 'i' for insert or 'd' for delete.\n");
    }
}
void freearr(int ***arr, int row){
	int i;
    if(*arr != NULL){
        for ( i = 0 ; i < row ; i++ ){
            free((*arr)[i]);
        }
        free(*arr);
        *arr = NULL;
        printf("Memory freed\n");
    }
}
int main(){
    int row = 10, col = 10, rowpos = 2, colpos = 3, val = 42;
    int **arr = NULL;
    initialize(&arr, NULL, row, col);
    printf("Array before:\n");
    printarr(arr, row);
    insertdelete(arr, row, col, rowpos, colpos, val);
    printf("\nArray After:\n");
    printarr(arr, row);
    freearr(&arr, row);
    return 0;
}
