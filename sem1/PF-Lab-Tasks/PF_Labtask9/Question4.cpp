#include <stdio.h>
#include <string.h>
int main(){
	int found = 0;
	char str[10];
	char arr[10][10] = {"Alice","Charlie","Aly","Harry"};
	printf("Enter a name to search: ");
	scanf("%s", &str);
	
	for(int i = 0; i<10;i++){
		if(strcmp(arr[i],str)==0){
			found = 1;
		}
	}
	if(!found){
		printf("Not found");
	}
	else{
		printf("Found");
	}
	return 0;
}
