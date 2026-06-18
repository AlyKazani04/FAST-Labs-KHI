#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{   
    char msg[BUFFER_SIZE] = "Greetings!";
    char readbuf[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    if (pipe(fd) == 1)
    {
        perror("pipe");
        exit(1);
    }

    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0) // parent
    {
        close(fd[READ_END]);
        write(fd[WRITE_END], msg, strlen(msg) + 1);
        close(fd[WRITE_END]);
        printf("Writing from parent: %s\n", msg);
    }

    if (pid == 0) // child
    {
        close(fd[WRITE_END]);
        read(fd[READ_END], readbuf, BUFFER_SIZE);
        close(fd[READ_END]);
        printf("Reading from child: %s\n", readbuf);
    }

    return 0;
}