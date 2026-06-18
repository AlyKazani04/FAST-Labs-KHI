#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

struct shared_data {
  int flag;
  char message[100];
};

int main() {
  int shm_fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);
  ftruncate(shm_fd, sizeof(struct shared_data));

  struct shared_data *ptr = mmap(NULL, sizeof(struct shared_data),
                                 PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

  ptr->flag = 0; // Start with Producer's turn

  for (int i = 1; i <= 5; i++) {
    // Busy Wait: Spin until flag is 0
    while (ptr->flag != 0)
      ;

    sprintf(ptr->message, "Update #%d", i);
    printf("Producer wrote: %s\n", ptr->message);

    ptr->flag = 1; // Hand over to Consumer
  }

  munmap(ptr, sizeof(struct shared_data));

  close(shm_fd);

  shm_unlink("/my_shm");

  return 0;
}
