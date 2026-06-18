#include <stdio.h>
#include <stdlib.h>
int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int*)malloc(size*sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed\n");
    }
    int max;
    int i;
    for( i = 0; i<size; i++){
        printf("Enter arr value %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    for( i = 0; i<size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("The biggest input: %d\n", max);
    free(arr);
    return 0;
}
