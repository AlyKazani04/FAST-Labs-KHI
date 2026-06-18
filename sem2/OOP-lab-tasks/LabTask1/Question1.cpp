#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	float arr[20] = {1.2,2.1,3.2,23.1};
	float *max, *oldptr;
	max = &arr[0];
	for(int i = 1; i<20; i++){
		if(arr[i] > *max){
			oldptr = max;
			max = &arr[i];
		}
	}
	cout<<*oldptr<<endl;
	return 0;
}
