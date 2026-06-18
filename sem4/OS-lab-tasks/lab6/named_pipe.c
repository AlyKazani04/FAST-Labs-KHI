#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/myfifo"

int main() {

  pid_t pid;

  mkfifo(FIFO_NAME, 0666);

  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid > 0) { // parent
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
      perror("open");
      exit(EXIT_FAILURE);
    }

    char buffer[BUFSIZ];
    int numbytes;
    while (1) {
      printf("Enter message: ");
      fgets(buffer, BUFSIZ, stdin);

      numbytes = write(fd, buffer, strlen(buffer));
      if (numbytes == -1) {
        perror("write");
        exit(EXIT_FAILURE);
      }

      if (strncmp(buffer, "exit", 4) == 0) {
        break;
      }
    }

    close(fd);
    unlink(FIFO_NAME);
    exit(EXIT_SUCCESS);
  }

  if (pid == 0) { // child
    int fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
      perror("open");
      exit(EXIT_FAILURE);
    }

    printf("Waiting for messages...\n");

    char buffer[BUFSIZ];
    int numbytes;
    while (1) {
      numbytes = read(fd, buffer, sizeof(buffer) - 1);
      if (numbytes == -1) {
        perror("write");
        exit(EXIT_FAILURE);
      }

      if (numbytes > 0) {
        buffer[numbytes] = '\0';
        printf("\nReader read: %s", buffer);
      }

      if (strncmp(buffer, "exit", 4) == 0 || numbytes == 0) {
        break;
      }
    }

    close(fd);
    exit(EXIT_SUCCESS);
  }

  unlink(FIFO_NAME);
  return EXIT_FAILURE;
}
