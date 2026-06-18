#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main() {
  // Dynamically allocate to avoid stack overflow
  float *A = (float *)malloc(SIZE * sizeof(float));
  float *B = (float *)malloc(SIZE * sizeof(float));
  float *C = (float *)malloc(SIZE * sizeof(float));

  // Initialize data
  for (int i = 0; i < SIZE; i++) {
    A[i] = 1.0f;
    B[i] = 2.0f;
  }

  clock_t start = clock();

  for (int i = 0; i < SIZE; i++) {
    C[i] = A[i] + B[i];
  }

  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Serial execution time: %f seconds\n", time_spent);

  free(A);
  free(B);
  free(C);
  return 0;
}
