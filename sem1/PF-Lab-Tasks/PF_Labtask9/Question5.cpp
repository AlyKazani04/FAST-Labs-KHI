#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
	char intext[100], key[100], cipher[100], temp[50];
	int inttext[100], intkey[100], intcipher[100];
	printf("Enter string to encrypt: ");
	scanf("%[^\n]%*c", intext);
	printf("Enter encryption key : ");
	scanf("%[^\n]%*c", key);
	
//	converting to uppercase
	for(int i = 0; i < strlen(intext);i++){
		intext[i] = toupper(intext[i]);
	}
	for(int i = 0; i < strlen(key);i++){
		key[i] = toupper(key[i]);
		temp[i] = key[i];
	}
	
//	filling key to strlen of intext with keys
	for(int i = 0; i<strlen(intext); i++){
		key[i] = temp[i%strlen(temp)];
	}

//	converting to ascii both the arrays
//	subtract 64 from all values
	for(int i = 0; i < strlen(intext);i++){
		inttext[i] = (int)intext[i];
		inttext[i] -= 64;
	}
	for(int i = 0; i < strlen(key);i++){
		intkey[i] = (int)key[i];
		intkey[i] -= 64;
	}
	
//	add values and store their mods
	for(int i = 0; i < strlen(intext);i++){
		intcipher[i] = (inttext[i] + intkey[i])%26;
		intcipher[i] += 64;
	}
//	convert ascii to char again
	for(int i = 0; i < strlen(intext);i++){
		cipher[i] = (unsigned char)intcipher[i];
	}
	cipher[strlen(intext)] = '\0';
	printf("%s", cipher);
}
