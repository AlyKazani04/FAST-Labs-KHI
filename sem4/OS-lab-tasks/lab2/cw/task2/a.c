#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv)
{
    const char* filename = "file.txt";
    char command[50] = "cat ";

    FILE* f = fopen(filename, "r");

    if(f == NULL)
    {
        perror("Error \'file_not_found\'");
        exit(1);
    }

    strcat(command, filename);
    system(command);

    fclose(f);

    return 0;
}