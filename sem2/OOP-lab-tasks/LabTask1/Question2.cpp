#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	int size = 10, total = 0;
	int arr[size] = { 1,2,3,4,5,6,7,8,9,2 };
	int *ptr;
	ptr = &arr[0];
	for(int i = 0; i < size ; i++){
		total += *(ptr + i);
	}
	cout<<"Total = "<<total;
}
