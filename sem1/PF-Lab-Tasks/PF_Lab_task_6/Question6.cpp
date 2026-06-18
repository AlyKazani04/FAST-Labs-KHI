#include <stdio.h>
int main(){
    int i, num, prime;
    prime = 1; 
    printf("Enter a number: "); 
    scanf("%d", &num); 
    if(num <= 1){ 
        prime = 0; 
    } 
	else{
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                prime = 0;
                break; 
            } 
        }
    }
    if(prime==1){
        printf("%d is a prime number.\n", num);
        int a = 0, b = 1, next;
        printf("%d ", a);
        while(b <= num){
            printf("%d ", b);
            next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
    }
	else{
        printf("%d is not a prime number.\n", num);
    }
}
