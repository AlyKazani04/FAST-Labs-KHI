#include <bits/stdc++.h>
using namespace std;

struct str_in{
	string subject;	
};

struct str_out{
	struct str_in strin_arr[3];
	int id;
};

int main(int argc, char** argv){
	int num;
	cout<<"Enter number of struct arrays to make: ";
	cin>>num;
	str_out* outarray = new str_out[num];
	for(int i = 0; i < num ; i++){
		cout<<"Enter outer struct "<<i+1<<"\'s id: ";
		cin>>outarray[i].id;
		for(int j = 0; j < 3; j++){
			cout<<"Enter inner struct "<<j+1<<"\'s subject: ";
			cin>>outarray[i].strin_arr[j].subject;
		}
	}
	for(int i = 0; i < num ; i++){
		cout<<"Outer Struct "<<i+1<<":"<<endl; 
		cout<<"Outer Struct ID: "<<outarray[i].id<<endl;
		for(int j = 0; j < 3; j++){
			cout<<"\tInner Struct "<<j+1<<"\'s subject: "<<outarray[i].strin_arr[j].subject<<endl;
		}
	}	
	return 0;
}
