#include <stdio.h>
int main() {
	int age, citizen;
printf("Enter your age");
scanf("%d", &age);
printf("Enter citizenship status(1 for citizen, 0 for non citizen) :");
scanf("%d", &citizen);
if (age >= 18 && citizen == 1) {
printf("You are eligible to vote.\n");
} else {
printf("You are not eligible to vote.\n");
}
return 0;
}