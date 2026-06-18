#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/myfifo"

int main() {
  pid_t pid;
  int fd;
  char message[50];

  mkfifo(FIFO_NAME, 0666);

  pid = fork();

  if (pid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid > 0) { // parent
    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    fd = open(FIFO_NAME, O_WRONLY);

    write(fd, message, strlen(message) + 1);
    printf("Parent sent: %s", message);

    close(fd);

    wait(NULL);
    unlink(FIFO_NAME);
  }

  if (pid == 0) { // child
    fd = open(FIFO_NAME, O_RDONLY);

    read(fd, message, sizeof(message));

    close(fd);

    int len = strlen(message);
    if (len > 0 && message[len - 1] == '\n')
      len--;

    printf("Printed in reverse: ");
    for (int i = len - 1; i >= 0; i--) {
      putchar(message[i]);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
  }

  return EXIT_SUCCESS;
}
