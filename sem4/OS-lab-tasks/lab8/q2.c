#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INTS 100

typedef struct {
  int vals[MAX_INTS];
  int size;
} Threadvals;

void *average_worker(void *args) {
  Threadvals *tv = (Threadvals *)args;

  double *avg = malloc(sizeof(double));
  double sum = 0;

  for (int i = 0; i < tv->size && i < MAX_INTS; i++) {
    sum += tv->vals[i];
  }
  *avg = sum / tv->size;

  return (void *)avg;
}

void *min_finder(void *args) {
  Threadvals *tv = (Threadvals *)args;
  int *min = malloc(sizeof(int));

  int curr_min = INT_MAX;

  for (int i = 0; i < tv->size && i < MAX_INTS; i++) {
    if (tv->vals[i] < curr_min) {
      curr_min = tv->vals[i];
    }
  }

  *min = curr_min;

  return (void *)min;
}

void *max_finder(void *args) {
  Threadvals *tv = (Threadvals *)args;
  int *max = malloc(sizeof(int));

  int curr_max = INT_MIN;

  for (int i = 0; i < tv->size && i < MAX_INTS; i++) {
    if (tv->vals[i] > curr_max) {
      curr_max = tv->vals[i];
    }
  }

  *max = curr_max;

  return (void *)max;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Enter an entire list of numbers!\n");
    exit(EXIT_FAILURE);
  }

  Threadvals *args = (Threadvals *)malloc(sizeof(Threadvals));
  args->size = argc - 1;
  for (int i = 1; i < argc; i++) {
    args->vals[i - 1] = atoi(argv[i]);
  }

  pthread_t tid[3];

  pthread_create(&tid[0], NULL, average_worker, (void *)args);
  pthread_create(&tid[1], NULL, min_finder, (void *)args);
  pthread_create(&tid[2], NULL, max_finder, (void *)args);

  void *res_avg, *res_min, *res_max;

  pthread_join(tid[0], &res_avg);
  pthread_join(tid[1], &res_min);
  pthread_join(tid[2], &res_max);

  printf("The average value is: %.2f\n", *(double *)res_avg);
  printf("The minimum value is: %d\n", *(int *)res_min);
  printf("The maximum value is: %d\n", *(int *)res_max);

  free(args);
  free(res_avg);
  free(res_min);
  free(res_max);
  return 0;
}
