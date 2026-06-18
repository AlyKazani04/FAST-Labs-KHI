#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

int balance = 1000;

pthread_mutex_t mutex;

void *adder(void *args) {
  for (int i = 0; i < 10; i++) {
    pthread_mutex_lock(&mutex);
    balance += 500;
    pthread_mutex_unlock(&mutex);
    printf("Added 500.\n");
    usleep(10);
  }

  return NULL;
}

void *deducter(void *args) {
  for (int i = 0; i < 10; i++) {
    pthread_mutex_lock(&mutex);
    if (balance > 200) {
      balance -= 200;
      printf("Deducted 200.\n");
    } else {
      printf("Insufficient balance, did not deduct.\n");
    }
    pthread_mutex_unlock(&mutex);
    usleep(10);
  }
  return NULL;
}

void *reader(void *args) {
  for (int i = 0; i < 10; i++) {
    pthread_mutex_lock(&mutex);
    printf("Balance: %d\n", balance);
    pthread_mutex_unlock(&mutex);
    usleep(10);
  }
  return NULL;
}

int main() {
  pthread_mutex_init(&mutex, NULL);

  pthread_t add, deduct, read;
  pthread_create(&add, NULL, adder, NULL);
  pthread_create(&deduct, NULL, deducter, NULL);
  pthread_create(&read, NULL, reader, NULL);

  pthread_join(add, NULL);
  pthread_join(deduct, NULL);
  pthread_join(read, NULL);

  pthread_mutex_destroy(&mutex);

  return 0;
}
