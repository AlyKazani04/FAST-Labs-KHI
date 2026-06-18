#include <stdio.h>
#include <stdlib.h>
int main(){
	int i, j, T, N, A;
//	printf("Num arrays:");
	scanf("%d", &T);
	int **arr = (int **)malloc(T * sizeof(int *));
	int *sizes = (int *)malloc(T * sizeof(int));
	int *maxvalues = (int *)malloc(T * sizeof(int)); 
	int *maxfreqs = (int *)malloc(T * sizeof(int));
	if(arr == NULL || sizes == NULL || maxvalues == NULL || maxfreqs == NULL){
		printf("Malloc failed.\n");
		return 1;
	}
	for( i = 0 ; i < T ; i++ ){
//		printf("Num terms:");
		scanf("%d", &N);
		sizes[i] = N;
		arr[i] = (int *)malloc(N*sizeof(int));
		if(arr[i] == NULL){
			printf("Malloc failed.\n");
			return 1;
		}
		for ( j = 0 ; j < N ; j++ ){
//			printf("term %d: ", j+1);
			scanf("%d", &arr[i][j]);
		}
	}
	for( i = 0 ; i < T ; i++ ){
		int *counts = (int *)calloc(1000, sizeof(int));
		if(counts == NULL){
			printf("Calloc failed.\n");
			return 1;
		}
		for( j = 0; j < sizes[i] ; j++){
            counts[arr[i][j]]++;
        }
        int maxfreq = 0;
        int val = 10000;
        for( j = 0; j < sizes[i] ; j++){
        	if(counts[arr[i][j]] > maxfreq || (counts[arr[i][j]] == maxfreq && arr[i][j] < val)){
        		maxfreq = counts[arr[i][j]];
        		val = arr[i][j];
			}
    	}
    	maxfreqs[i] = maxfreq;
    	maxvalues[i] = val;
		free(counts);
	}
	for( i = 0 ; i < T ; i++ ){
//    	printf("Number with maximum frequency in array %d: %d (Frequency: %d)\n", i + 1, maxvalues[i], maxfreqs[i]);
    	printf("%d\n", maxvalues[i]);
    }
	for( i = 0 ; i < T ; i++ ){
		free(arr[i]);
	}
	free(arr);
	free(sizes);
	free(maxfreqs);
	free(maxvalues);
	return 0;
}
