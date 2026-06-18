#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/myfifo"

int main(void) {

  int fd, val1, val2;
  char buffer[100];
  pid_t pid;

  mkfifo(FIFO_NAME, 0666);

  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid > 0) { // parent
    printf("Enter 2 vals like (val1 val2): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      fd = open(FIFO_NAME, O_WRONLY);

      write(fd, buffer, sizeof(buffer));

      close(fd);
    }

    wait(NULL);
    unlink(FIFO_NAME);
  }

  if (pid == 0) { // child
    int choice;
    fd = open(FIFO_NAME, O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    close(fd);

    sscanf(buffer, "%d %d", &val1, &val2);

  again:
    printf("\n1. Sum\n2. Product\n");
    printf("Enter Choice: ");
    if (scanf("%d", &choice) != 1) {
      while (getchar() != '\n')
        ;
      goto again;
    }

    switch (choice) {
    case 1:
      printf("Result: %d\n", (val1 + val2));
      break;
    case 2:
      printf("Result: %d\n", (val2 * val1));
      break;
    default:
      printf("Invlaid Choice! Try Again.\n");
      goto again;
    }
  }

  return EXIT_SUCCESS;
}
