#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int args[100];
  for (int i = 1; i < argc; i++) {
    args[i - 1] = atoi(argv[i]);
  }

  int pid1 = fork();
  if (pid1 == 0) { // child 1
    int total = 0;
    for (int i = 0; i < argc - 1; i++) {
      total += args[i];
    }

    char buf[100];
    int len = snprintf(buf, sizeof(buf), "Child 1 says: Sum = %d\n", total);
    write(1, buf, len);

    int pid2 = fork();
    if (pid2 == 0) { // child 2
      float avg = (float)total / (argc);
      len = snprintf(buf, sizeof(buf), "Child 2 says: Average = %.2f\n", avg);
      write(1, buf, len);
      exit(0);
    }

    wait(NULL);
    exit(0);
  }

  wait(NULL);

  int pid3 = fork();
  if (pid3 == 0) { // child 3
    int max = 0;
    for (int i = 0; i < argc; i++) {
      if (args[i] > max) {
        max = args[i];
      }
    }

    char buf[100];
    int len = snprintf(buf, sizeof(buf), "Child 3 says: Maximum = %d\n", max);
    write(1, buf, len);

    exit(0);
  }

  wait(NULL);

  return 0;
}
