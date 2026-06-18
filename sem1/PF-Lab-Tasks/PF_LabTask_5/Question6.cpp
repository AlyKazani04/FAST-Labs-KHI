#include <stdio.h>
int main(){
	int count, n;
	printf("enter a number :\n"); //for the max int value : 2147483647 or 2^31
	scanf("%d", &n);
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	count += n & 1; n = n>>1;
	printf("Number of ones in the binary representation of this number is %d", count);	
}
