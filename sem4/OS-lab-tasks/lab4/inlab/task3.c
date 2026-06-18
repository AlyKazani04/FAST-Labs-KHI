#include <stdio.h>
#include <unistd.h>

int main() {
  char buf[100];
  int len = snprintf(buf, sizeof(buf), "Process ID: %d\n", getpid());
  write(1, buf, len);

  len = snprintf(buf, sizeof(buf), "Parent Process ID: %d\n", getppid());
  write(1, buf, len);

  len = snprintf(buf, sizeof(buf), "User ID: %d\n", getuid());
  write(1, buf, len);

  return 0;
}
