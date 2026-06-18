#include <bits/stdc++.h>
using namespace std;

int* double_size(int* arr, int size){
	int* newarr = new int[size*2];
	for(int i = 0; i < size; i++){
		newarr[i] = arr[i];
	}
	delete[] arr;
	return newarr;
}

int main(int argc, char**argv){
	int* arr = new int[5];
	int num, size = 5, count = 0;
	while(1){
		cout<<"zero to end"<<endl;
		cout<<"Enter a num to add to the array: ";
		cin>>num;
		switch(num){
			case 0:
				for(int i = 0 ; i < count ; i++){
					cout<<arr[i]<<" ";
				}
				delete[] arr;
				return 0;
				
			default: 
				if(count == size){
					arr = double_size(arr, size);
					size*=2;	
				}
				arr[count] = num;
				count++;
				break;
		}         
	}
	return 0;
}
