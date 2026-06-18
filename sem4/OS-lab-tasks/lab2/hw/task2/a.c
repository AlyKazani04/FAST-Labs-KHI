#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int list[100];
    for(int i = 1; i < argc; i++)
    {
        list[i - 1] = atoi(argv[i]);
    }
    int index = list[0];

    for(int i = 1; i < argc - 1; i++)
    {
        if(list[i] == index + 1)
        {
            index++;
            continue;
        }
        else
        {
            printf("Missing: %d\n", index + 1);
            index++;
            i--;
        }
    }

    return 0;
}