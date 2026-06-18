#include <stdio.h>
typedef struct{
	int area, exchange, number;
} Phone;
int enternum(Phone *phone){
	printf("Enter area: ");
	scanf("%3d", &phone->area);
	printf("Enter exchange: ");
	scanf("%3d", &phone->exchange);
	printf("Enter number: ");
	scanf("%4d", &phone->number);
	printf("____________________\n\n");
	return 0;
}
int displaynum(Phone phone){
	printf("(%03d) %03d-%04d\n", phone.area, phone.exchange, phone.number);
	return 0;
}
int main(){
	Phone phone1 = { 92, 300, 2000};
	Phone phone2;
	enternum(&phone2);
	printf("My phone number :"); 
	printf(displaynum(phone1));
	printf("Your phone number :"); 
	printf(displaynum(phone2));
	return 0;
}
