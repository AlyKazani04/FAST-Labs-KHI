#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class User{
	public:
		int Age;
		string Name;		
};

int main(int argc, char** argv){
	User me;
	
	//main method
	//me.Age = atoi(argv[1]);
	//me.Name = argv[2];
	
	//hardcoded
	me.Age = 24;
	me.Name = "Teo";
	cout<<"My name is "<<me.Name<<" and I am "<<me.Age<<" years old."<<endl;
	return 0;
}
