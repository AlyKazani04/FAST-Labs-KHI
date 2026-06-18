#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  if (fork() == 0) {
    execlp("ls", "ls", "-1", (char *)NULL);
    exit(EXIT_SUCCESS);
  }
  wait(NULL);

  write(1, "\n", 1);

  if (fork() == 0) {
    execlp("mkdir", "mkdir", "toast", NULL);
    exit(EXIT_SUCCESS);
  }
  wait(NULL);

  if (fork() == 0) {
    execlp("ls", "ls", "-1", NULL);
    exit(EXIT_SUCCESS);
  }
  wait(NULL);

  write(1, "\n", 1);

  if (fork() == 0) {
    execlp("mv", "mv", "toast", "bread", NULL);
    exit(EXIT_SUCCESS);
  }
  wait(NULL);

  if (fork() == 0) {
    execlp("ls", "ls", "-1", NULL);
    exit(EXIT_SUCCESS);
  }
  wait(NULL);

  if (fork() == 0) {
    execlp("rmdir", "rmdir", "bread", NULL);
    exit(EXIT_SUCCESS);
  }
  wait(NULL);

  write(1, "\n", 1);

  execlp("ls", "ls", "-1", NULL);

  return 0;
}
