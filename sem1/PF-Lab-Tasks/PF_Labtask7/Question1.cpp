#include<stdio.h>
int main() {
    int arr[]= {1,1,1,1,1,1,5,1,1,1,1,1}, i=-1, var, size, found, num;
    size = sizeof(arr)/sizeof(arr[0]);
    found=0;
    printf("Array = {1,1,1,1,1,1,5,1,1,1,1,1}");
    printf("\nEnter integer to search : ");
    scanf("%d",&num);
    while(found!=1 && i<size) {
        i+=1;
        var=arr[i];
        if(var==num) {
            found=1;
            printf("%d found at index %d ",num,i);
        }
    }
    if(found==0){
            printf("Not found");
    }        
}
