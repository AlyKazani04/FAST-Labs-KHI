/*
  The Producer-Consumer Problem (Bounded Buffer)

  This solution uses a mutex to ensure exclusive access to the buffer and two
  counting semaphores to track empty and full slots.
*/

#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty;           // Tracks empty slots (initial value: BUFFER_SIZE)
sem_t full;            // Tracks full slots (initial value: 0)
pthread_mutex_t mutex; // Protects buffer access

void *producer(void *arg) {
  int item = 1;
  while (1) {
    sem_wait(&empty);           // Wait if buffer is full
    pthread_mutex_lock(&mutex); // Critical Section start

    buffer[in] = item++;
    in = (in + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mutex); // Critical Section end
    sem_post(&full);              // Signal that buffer has an item
  }
}

void *consumer(void *arg) {
  while (1) {
    sem_wait(&full);            // Wait if buffer is empty
    pthread_mutex_lock(&mutex); // Critical Section start

    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mutex); // Critical Section end
    sem_post(&empty);             // Signal that a slot is now free
  }
}
