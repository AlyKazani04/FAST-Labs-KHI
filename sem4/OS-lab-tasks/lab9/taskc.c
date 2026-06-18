#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int sig) { printf("Parent: SIGINT recieved...\n"); }

void child_handler(int sig) { printf("SIGCHLD recieved...\n"); }

int main() {

  int pid = fork();
  if (pid == 0) { // child
    signal(SIGINT, SIG_IGN);
    for (int i = 0; i < 3; i++) {
      printf("Child ID: %d\n", getpid());
      sleep(2);
    }
  } else {
    signal(SIGCHLD, child_handler);
    signal(SIGINT, handler);

    printf("Parent ID: %d\n", getpid());
    wait(NULL);
    printf("Parent noticed that the Child has ended.\n");
  }

  return 0;
}
