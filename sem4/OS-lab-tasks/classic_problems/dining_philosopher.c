/*
  The Dining Philosophers Problem

  To avoid deadlock (where everyone picks up a left chopstick and waits
  forever), this code makes the last philosopher pick up their chopsticks in a
  different order.
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define MAX_PHIL 5

sem_t chopsticks[MAX_PHIL];

void *philosopher(void *num) { // Passing the Thread ID as the parameter
  int id = *(int *)num;
  int left = id;
  int right = (id + 1) % MAX_PHIL;

  // If it's the last philosopher, swap the pick-up order.
  if (id == MAX_PHIL - 1) {
    sem_wait(&chopsticks[right]); // Pick up Right first
    sem_wait(&chopsticks[left]);  // Pick up Left second
  } else {
    sem_wait(&chopsticks[left]);  // Pick up Left first
    sem_wait(&chopsticks[right]); // Pick up Right second
  }

  printf("Philosopher %d is eating.\n", id);

  // Release the chopsticks (ideally in reverse order of acquisition)
  if (id == MAX_PHIL - 1) {
    sem_post(&chopsticks[left]);
    sem_post(&chopsticks[right]);
  } else {
    sem_post(&chopsticks[right]);
    sem_post(&chopsticks[left]);
  }

  return NULL;
}
