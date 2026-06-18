#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("Fork Failed!");
        exit(1);
    }

    if(pid == 0)
    {
        printf("Forked Process ID: %d\n", getpid());
    }
    else
    {
        pid_t pid2 = fork();
        if(pid2 < 0)
        {
            perror("Fork Failed!");
            exit(1);
        }
        if(pid2 == 0)
        {
            printf("Other Forked Process' Parent ID: %d\n", (int)getppid());
            exit(0);
        }   

        wait(NULL);
        wait(NULL);
        printf("Parent ending...\n");
    }

    return 0;
}