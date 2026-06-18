#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int vals[100];
	for(int i = 1; i < argc; i++)
	{
		vals[i-1] = atoi(argv[i]);
	}

	int sum = 0;
	for(int i = 0; i < argc - 1; i++)
	{
		sum += vals[i];
	}
	float avg = (float)sum / (argc - 1);
	printf("Sum: %d\nAverage: %.2f\n", sum, avg);

	return 0;
}
