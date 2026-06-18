#include <stdio.h>
typedef struct{
	char number[20];
	char description[20];
	int quantity;
	float price;
} Invoice;
float calculateinvoice(Invoice invoice){
	float result;
	if(invoice.price < 0)
		invoice.price = 0;
	if(invoice.quantity < 0)
		invoice.quantity = 0;
	result = invoice.price*invoice.quantity;
	return result;
}
int createinvoice(Invoice invoice){
	printf("Name\tPartID\tQuantity  Price\n");
	printf("__________________________________\n\n");
	printf("%s\t %s\t   %d\t  %.2f\n\n", invoice.description, invoice.number, invoice.quantity, invoice.price);
	printf("__________________________________\n\n");
	printf("Total cost : %.2f\n\n", calculateinvoice(invoice));
}
int main(){
	Invoice invoice = {"ab100", "faucet", 3, 120.5};
	Invoice testinvoice = {"cb432", "hammer", 23, -123.4};
	createinvoice(invoice);
	createinvoice(testinvoice);
	return 0;
}
