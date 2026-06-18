#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  if (fork() == 0) {
    execlp("ls", "ls", NULL);
    exit(EXIT_SUCCESS);
  }

  wait(NULL);

  return 0;
}
