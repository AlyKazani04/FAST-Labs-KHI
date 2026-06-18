#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid = fork(); // Create new process
  if (pid == 0) {

    // Child process
    printf("Child Process:\n");
    printf("PID: %d\n", getpid());
    printf("Parent PID: %d\n", getppid());

    sleep(2); // Sleep for 2 seconds

    printf("Child finished.\n");
  } else {

    // Parent process
    // wait(NULL); // Comment this line to test "without wait"

    printf("Parent Process:\n");
    printf("PID: %d\n", getpid());
    printf("Child PID: %d\n", pid);
    printf("Parent finished.\n");
  }
  return 0;
}
