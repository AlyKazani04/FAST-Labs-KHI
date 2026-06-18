#include <bits/stdc++.h>
using namespace std;

void* Inc_Array(void* a, int size){
	int* arr = static_cast<int*>(a);
	for(int i = 0 ; i < size;i++){
		arr[i]++;
	}
	return static_cast<void*>(arr);
}

int main(int argc, char** argv){
	
	int* arr = new int[argc-1];
	
	for(int i = 0 ; i < argc-1; i++){
		arr[i] = atoi(argv[i+1]);
	}
	
//	current arr
	for(int k = 0 ; k < argc-1 ; k++){
		cout<<arr[k]<<" ";
	}
	cout<<endl;
	
	//cast as void in parameter
	Inc_Array(static_cast<void*>(arr), argc-1);
	
	//cast back to int
	static_cast<int*>(arr);
	
//	Result
	for(int j = 0 ; j < argc-1 ; j++){
		cout<<arr[j]<<" ";
	}
	
	delete[] arr;
	return 0;
}
