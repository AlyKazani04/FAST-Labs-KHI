#include <stdio.h>
#include <string.h>
int main(){
	char preuser[] ="admin";
	char prepass[] ="1234";
	char user[10];
	char pass[10];
	
	printf("Enter username: ");
	scanf("%s", user);
	printf("Enter password: ");
	scanf("%s", pass);
	if(strcmp(preuser,user)==0 && strcmp(prepass,pass)==0){
		printf("Access granted");
	}
	else{
		printf("Access denied");
	}
}
