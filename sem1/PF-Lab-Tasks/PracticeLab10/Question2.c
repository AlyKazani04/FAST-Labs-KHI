#include <stdio.h>

int cut(int rope, int cutamount, int count){
	if(rope<=0){
		return count;
	}
	else{
		count +=1;
		cut(rope-cutamount, cutamount, count);
	}
}
int checkRope(int rope){
    int cutFor1 = cut(rope,1,0);
    int cutFor2 = cut(rope,2,0);
    int cutFor3 = cut(rope,3,0);
    
    int maxCut = (cutFor1 > cutFor2) ? (cutFor1 > cutFor3 ? cutFor1 : cutFor3) : (cutFor2 > cutFor3 ? cutFor2 : cutFor3);
    return maxCut;
}
int main(){
    int rope = 50; //Example value
    if(rope >= 0){
        printf("The maximum number of pieces the rope can be cut into is: %d\n", checkRope(rope));
    }
	else{
        printf("Rope Length cannot be negative.");
    }
    return 0;
}
