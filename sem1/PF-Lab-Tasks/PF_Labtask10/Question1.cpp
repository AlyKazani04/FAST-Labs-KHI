#include <stdio.h>
#include <string.h>

char reversePrint(char *sentence){
	if(*sentence){
		reversePrint(sentence+1);
		printf("%c",*sentence);
	}
}
int main(){
	char sentence[100];
	printf("Enter a String: ");
	scanf("%[^\n]%*c", sentence);
	reversePrint(sentence);
}