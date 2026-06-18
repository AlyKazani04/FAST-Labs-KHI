#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int sig) { printf("SIGINT received...\n"); }

int main() {

  int pid = fork();
  if (pid == 0) { // child
    while (1) {
      printf("Child PID: %d\n", getpid());
      sleep(2);
    }
  } else {
    signal(SIGINT, handler);

    printf("Parent ID: %d\n", getpid());
    wait(NULL);
    printf("Parent exiting...\n");
  }
  return 0;
}
