#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

struct shared_data {
  int flag;
  char message[100];
};

int main() {
  int shm_fd = shm_open("/my_shm", O_RDWR, 0666);
  struct shared_data *ptr = mmap(NULL, sizeof(struct shared_data),
                                 PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

  for (int i = 1; i <= 5; i++) {
    // Busy Wait: Spin until flag is 1
    while (ptr->flag != 1)
      ;

    printf("Consumer read: %s\n", ptr->message);

    ptr->flag = 0;
  }

  munmap(ptr, sizeof(struct shared_data));
  close(shm_fd);

  return 0;
}
