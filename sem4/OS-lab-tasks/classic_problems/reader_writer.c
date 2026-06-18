/*
  The Readers-Writers Problem

  This implementation gives readers priority, allowing multiple readers at once
  but requiring exclusive access for a writer.
*/

#include <pthread.h>
#include <semaphore.h>

sem_t rw_mutex;        // Semaphore for writer access
pthread_mutex_t mutex; // Protects the read_count variable
int read_count = 0;

void *writer(void *arg) {
  sem_wait(&rw_mutex); // Wait for exclusive access
  // ... Writing to shared data ...
  sem_post(&rw_mutex); // Release access
  return NULL;
}

void *reader(void *arg) {
  pthread_mutex_lock(&mutex);
  read_count++;
  if (read_count == 1) // First reader locks the writer out
    sem_wait(&rw_mutex);
  pthread_mutex_unlock(&mutex);

  // ... Reading shared data ...

  pthread_mutex_lock(&mutex);
  read_count--;
  if (read_count == 0) // Last reader allows writers back in
    sem_post(&rw_mutex);
  pthread_mutex_unlock(&mutex);
  return NULL;
}
