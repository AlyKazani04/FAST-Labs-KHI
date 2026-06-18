#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class DynamicArray{
	int* integers;
	int length;
	public:
		DynamicArray(){
			length = 0;
			integers = nullptr;
		}
		DynamicArray(int n) : length(n){
			integers = new int[length]{0};
		}
		//copy
		DynamicArray(const DynamicArray& other) : length(other.length){
			integers = new int[length];
			for(int i = 0; i < length; i++){
				integers[i] = other.integers[i];
			}
		}
		//move
		DynamicArray(DynamicArray&& other) noexcept : length(other.length), integers(other.integers){
			other.integers = nullptr;
			other.length = 0;
		}
		//copy assignment operator
		DynamicArray& operator=(const DynamicArray& other){
			if(this == &other){
				return *this;
			}
			delete[] integers;
			length = other.length;
			integers = new int[length];
			copy(other.integers, other.integers + other.length, integers);
			return *this;
		}
		//move assignment operator
		DynamicArray& operator=(DynamicArray&& other) noexcept{
			if(this == &other){
				return *this;
			}
			length = other.length;
			integers = new int[length];
			other.integers = nullptr;
			other.length = 0;
			return *this;
			
		}
		//destr
		~DynamicArray(){
			delete[] integers;
		}
		int size() const{
			return length;
		}
		//at()
		int& at(int index){
			if(index >= length){
				throw out_of_range("Out of range");
			}
			return integers[index];
		}
		//relength
		void resize(int newlength){
			int* newint = new int[newlength + 1];
			int minimum_length = (newlength < length) ? newlength : length;
			copy(integers, integers + minimum_length, newint);
			delete[] integers;
			integers = newint;
			length  = newlength;
		}
};

int main(int argc, char** argv){
	DynamicArray arr(5);
	arr.at(2) = 10;
	cout<<"Size: "<<arr.size()<<endl<<"Value at index 2: "<<arr.at(2)<<endl;
	arr.resize(10);
	cout<<"Resized to: "<<arr.size()<<endl;
	return 0;
}
