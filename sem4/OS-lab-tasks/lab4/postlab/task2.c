#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t parent_id = getpid();
  char buf[100];

  int len = snprintf(buf, sizeof(buf), "%d\n", parent_id);
  write(1, buf, len);

  int pid = fork();
  if (pid == 0) {
    len =
        snprintf(buf, sizeof(buf), "Child process, parent id: %d\n", getppid());
    write(1, buf, len);
    exit(EXIT_SUCCESS);
  }

  wait(NULL);

  len = snprintf(buf, sizeof(buf), "Parent process, child id: %d\n", pid);
  write(1, buf, len);

  return 0;
}
