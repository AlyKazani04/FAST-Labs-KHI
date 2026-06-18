#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    for (int i = 0; i < 100; i++)
    {
        if(pid == 0)
        {
            printf("I am child process!\n");
        }
        else
        {
            printf("I am parent process!\n");
        }
    }

    return 0;
}