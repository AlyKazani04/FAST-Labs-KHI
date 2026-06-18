#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1
#define BUFSIZE 20

int main() {
  int fd[2];
  char write_msg[BUFSIZE] = "Hello!";
  char read_msg[BUFSIZE];
  pid_t pid;

  if (pipe(fd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) { // child
    close(fd[WRITE_END]);
    read(fd[READ_END], read_msg, strlen(write_msg) + 1);
    close(fd[READ_END]);
    printf("Reading: %s", read_msg);
    exit(EXIT_SUCCESS);
  }

  if (pid > 0) { // parent
    close(fd[READ_END]);
    write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
    close(fd[WRITE_END]);
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
