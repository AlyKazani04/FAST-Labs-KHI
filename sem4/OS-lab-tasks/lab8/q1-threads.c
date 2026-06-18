#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SIZE 10000000
#define NUM_THREADS 10

typedef struct {
  float *A, *B, *C;
  int start;
  int end;
} ThreadData;

void *vector_add_thread(void *arg) {
  ThreadData *data = (ThreadData *)arg;
  for (int i = data->start; i < data->end; i++) {
    data->C[i] = data->A[i] + data->B[i];
  }
  return NULL;
}

int main() {
  float *A = malloc(SIZE * sizeof(float));
  float *B = malloc(SIZE * sizeof(float));
  float *C = malloc(SIZE * sizeof(float));

  pthread_t threads[NUM_THREADS];
  ThreadData thread_data[NUM_THREADS];

  for (int i = 0; i < SIZE; i++) {
    A[i] = 1.0f;
    B[i] = 2.0f;
  }

  struct timeval start, end;
  gettimeofday(&start, NULL);

  int chunk = SIZE / NUM_THREADS;
  for (int i = 0; i < NUM_THREADS; i++) {
    thread_data[i].A = A;
    thread_data[i].B = B;
    thread_data[i].C = C;
    thread_data[i].start = i * chunk;
    thread_data[i].end = (i == NUM_THREADS - 1) ? SIZE : (i + 1) * chunk;

    pthread_create(&threads[i], NULL, vector_add_thread, &thread_data[i]);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  gettimeofday(&end, NULL);
  double delta =
      (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

  printf("Concurrent execution time (10 threads): %f seconds\n", delta);

  free(A);
  free(B);
  free(C);
  return 0;
}
