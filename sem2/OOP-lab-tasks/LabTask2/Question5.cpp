#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

struct Object{
	string name;
	int id;
};

bool compare_Id(Object &a, Object &b){
    return a.id < b.id;
}

bool compare_Name(Object &a, Object &b){
	return a.name[0] < b.name[0];
}

int main(int argc, char** argv){
	int id_in;
	string name_in;
	int num;
	cout<<"Enter a number of structs: ";
	cin>>num;
	Object obj_arr[num];
	for(int i = 0; i < num ; i++){
		cout<<"Enter struct "<<i+1<<" ID: ";
		cin>>id_in;
		obj_arr[i].id = id_in;
		cout<<"Enter struct "<<i+1<<" Name: ";
		cin>>name_in;
		obj_arr[i].name = name_in;
	}
	sort(obj_arr, obj_arr + num, compare_Id);
	cout<<"Sorted by ID: "<<endl;
	for(int j = 0; j < num ; j++){
		cout<<"\tID "<<j+1<<": "<<obj_arr[j].id<<endl;
		cout<<"\tName "<<j+1<<": "<<obj_arr[j].name<<endl;
	}
	sort(obj_arr, obj_arr + num, compare_Name);
	cout<<"Sorted by Name: "<<endl;
	for(int j = 0; j < num ; j++){
		cout<<"\tID "<<j+1<<": "<<obj_arr[j].id<<endl;
		cout<<"\tName "<<j+1<<": "<<obj_arr[j].name<<endl;
	}
	return 0;
}
