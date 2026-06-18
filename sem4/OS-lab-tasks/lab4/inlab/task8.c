#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int stop_flag = 0;

void handle_alarm(int sig) { stop_flag = 1; }

int main() {
  signal(SIGALRM, handle_alarm);
  char buf[50];

  int len =
      snprintf(buf, sizeof(buf), "Alarm set for 5 secs...\nSleeping for 10\n");

  write(1, buf, len);

  alarm(5);

  len = snprintf(buf, sizeof(buf), "Sleeping...\n");

  for (; !stop_flag;) {
    sleep(1);
    write(1, buf, len);
  }

  len = snprintf(buf, sizeof(buf), "Exiting...\n");
  write(1, buf, len);

  return 0;
}
