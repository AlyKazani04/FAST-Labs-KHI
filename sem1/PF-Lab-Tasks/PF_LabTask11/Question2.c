#include <stdio.h>

int main(){
	char string[100];
	FILE *fptr;
	fptr = fopen("text.txt","r");
	fgets(string, 100 , fptr);
	printf("%s", string);
	fclose(fptr);
	return 0;	
}
