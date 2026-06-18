#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before replacing the process\n");
    execl("/bin/echo", "echo", "Hello from exec!", NULL);
    printf("After exec - will this line run?\n");
    return 0;
}