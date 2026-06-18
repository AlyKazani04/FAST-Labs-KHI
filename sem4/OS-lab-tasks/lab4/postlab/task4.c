#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 1024

void listdir(const char *name, int indent) {
  DIR *dir;
  struct dirent *entry;

  if (!(dir = opendir(name))) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char path[MAX_PATH];

    snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);

    char buf[MAX_PATH];
    int len = snprintf(buf, sizeof(buf), "%*s%s\n", indent, "", entry->d_name);

    write(1, buf, len);

    if (entry->d_type == DT_DIR) {
      listdir(path, indent + 2);
    }
  }

  closedir(dir);
}

int main() {
  listdir(".", 0);

  return EXIT_SUCCESS;
}
