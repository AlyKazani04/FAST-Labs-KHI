#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/myfifo"

int main() {
  int pid;
  int fd;
  char message[100];

  // Step 1: Create FIFO
  mkfifo(FIFO_NAME, 0666);

  // Step 2: Fork process
  pid = fork();
  if (pid < 0) {
    printf("Fork failed!\n");
    return 1;
  } else if (pid == 0) {

    // Child process → Reader
    fd = open(FIFO_NAME, O_RDONLY);
    read(fd, message, sizeof(message));

    printf("Child received: %s\n", message);
    close(fd);
  } else {

    // Parent process → Writer
    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);
    fd = open(FIFO_NAME, O_WRONLY);
    write(fd, message, strlen(message) + 1); // +1 for null terminator

    close(fd);
    printf("Parent sent the message!\n");
  }

  return 0;
}
