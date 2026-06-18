#include <stdio.h>
int main(){
    int num, oldnum, total, r, n, var, power;
    n = 0;
    total = 0;
    printf("Enter a num:");
    scanf("%d", &num);
    oldnum = num;
    var = num;
    while(var != 0){
        var = var / 10;
        n++;
    }
    var = num;
    while(var != 0){
        r = var % 10;
        power = 1;
        for(int i = 0; i < n; i++){
            power *= r;
        }
        total += power;
        var = var/10; 
    }
    if(total==oldnum){
        printf("Armstrong number found.");
    }
	else{ 
        printf("Not an Armstrong number.");
    }
}
