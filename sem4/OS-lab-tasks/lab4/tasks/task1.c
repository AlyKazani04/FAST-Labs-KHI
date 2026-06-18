#include <stdio.h>
#include <unistd.h>
int main() {
  int a = 1;
  fork();
  a += 1;
  fork();
  a += 2;
  printf("PID: %d, a = %d\n", getpid(), a);
  return 0;
}
