#include <stdio.h>
#include <ctype.h>
int main(){
	int c;
	FILE *file1 = fopen("file1.txt","r");
	FILE *file2 = fopen("file2.txt","w");
	while ((c = fgetc(file1)) != EOF){
		c = toupper(c);
		printf("%c", c);
		fputc(c, file2);
	}
	fclose(file1);
	fclose(file2);
	return 0;
}

