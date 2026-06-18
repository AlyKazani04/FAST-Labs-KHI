#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  if (fork() == 0) {
    execlp("pwd", "pwd", NULL);
    exit(EXIT_SUCCESS);
  }

  wait(NULL);

  if (fork() == 0) {
    execlp("ls", "ls", NULL);
    wait(EXIT_SUCCESS);
  }

  wait(NULL);

  return 0;
}
