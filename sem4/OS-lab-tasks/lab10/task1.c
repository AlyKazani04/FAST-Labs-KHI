#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TOTAL_SPACES 6
#define NUM_CARS 10

int spaces = TOTAL_SPACES;

sem_t empty_space, full_space;
pthread_mutex_t mutex;

void *parked_sim(void *args) {
  sem_wait(&empty_space);

  pthread_mutex_lock(&mutex);
  sleep(rand() % 3); // using parking space
  printf("A Car just parked. Spaces left: %d\n", --spaces);
  pthread_mutex_unlock(&mutex);

  sem_post(&full_space);

  return NULL;
}

void *leaving_sim(void *args) {
  sem_wait(&full_space);

  pthread_mutex_lock(&mutex);
  sleep(rand() % 3); // leaving
  printf("A Car left. Spaces left: %d\n", ++spaces);
  pthread_mutex_unlock(&mutex);

  sem_post(&empty_space);

  return NULL;
}

int main() {
  printf("Total Parking Spots: %d\n", TOTAL_SPACES);
  sem_init(&empty_space, 0, TOTAL_SPACES);
  sem_init(&full_space, 0, 0);
  pthread_mutex_init(&mutex, NULL);

  pthread_t parkers[NUM_CARS];
  pthread_t leavers[NUM_CARS];

  for (int i = 0; i < NUM_CARS; i++) {
    pthread_create(&parkers[i], NULL, parked_sim, NULL);
  }

  for (int i = 0; i < NUM_CARS; i++) {
    pthread_create(&leavers[i], NULL, leaving_sim, NULL);
  }

  for (int i = 0; i < NUM_CARS; i++) {
    pthread_join(parkers[i], NULL);
  }

  for (int i = 0; i < NUM_CARS; i++) {
    pthread_join(leavers[i], NULL);
  }

  sem_destroy(&empty_space);
  sem_destroy(&full_space);
  pthread_mutex_destroy(&mutex);
  return 0;
}
