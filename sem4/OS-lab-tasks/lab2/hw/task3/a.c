#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE *file;
    char *filename = "seq.txt";
    int list[100];

    file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }

    int index = fscanf(file, "%d", & list[0]);
    
    for(int i = 1; i < 100; i++)
    {
        if(fscanf(file, "%d", &list[i]) == 1)
        {
            while(list[i] != index + 1)
            {
                printf("Missing: %d\n", index + 1);
                index++;
            }
            index++;
            continue;
        }
        else
        {
            break;
        }
    }
    
    fclose(file);

    return 0;
}