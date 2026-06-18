#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

int main()
{
    int fd;
    char buffer[BUFSIZ];
    char prev[BUFSIZ];
    ssize_t num_bytes;

    fd = open(FIFO_FILE, O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    int len;

    printf("Waiting for messages...\n");

    while (1)
    {
        num_bytes = read(fd, buffer, BUFSIZ - 1);
        
        if (strcmp(prev, buffer) == 0) continue;
        
        
        len = sprintf(prev, "%s", buffer);
        
        if (num_bytes == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        
        if (num_bytes > 0)
        {
            buffer[num_bytes] = '\0';

            printf("Consumer: %s\n", buffer);

            if (strncmp(buffer, "exit", 4) == 0)
            {
                break;
            }
        }
        else if (num_bytes == 0)
        {
            break;
        }
    }

    close(fd);

    return EXIT_SUCCESS;
}