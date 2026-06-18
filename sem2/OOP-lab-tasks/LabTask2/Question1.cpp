#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
	int* arr = new int[argc-1];
	for(int i = 0; i < argc-1 ; i++){
		arr[i] = atoi(argv[i+1]);
	}
	int total = 0;
	for(int i = 0 ; i < argc-1 ; i++){
		total += *(arr+i);
	}
	cout<<"Total: "<<total<<endl;
	delete[] arr;
	return 0;
}