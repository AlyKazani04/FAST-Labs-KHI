#include <asm-generic/errno-base.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {

  if (argc != 3) {
    errno = EINVAL;
    perror("./t3");
    exit(EXIT_FAILURE);
  }

  ssize_t bytes_read;
  char buf[100];

  int fdsrc = open(argv[1], O_RDONLY);
  if (fdsrc == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  int fddest = open(argv[2], O_CREAT | O_WRONLY | O_APPEND);
  if (fddest == -1) {
    perror("open");
    close(fdsrc);
    exit(EXIT_FAILURE);
  }

  while ((bytes_read = read(fdsrc, buf, sizeof(buf))) > 0) {
    if (write(fddest, buf, bytes_read) == -1) {
      perror("write");
      close(fdsrc);
      close(fddest);
      exit(EXIT_FAILURE);
    }
  }

  if (bytes_read == -1) {
    perror("read");
    close(fdsrc);
    close(fddest);
    exit(EXIT_FAILURE);
  }

  close(fdsrc);
  close(fddest);

  return 0;
}
