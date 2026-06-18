#include <iostream>
using namespace std;

class Student{
	const int roll_no;//rollno declared but not assigned
	public:
		Student(int num) : roll_no(num){}
		void displayrno(){
			cout<<roll_no<<endl;
		}
};

int main(int argc, char** argv){
	int val;
	cout<<"Enter a roll no: ";
	cin>>val;//value taken at runtime
	Student s(val);//value assigned at runtime
	cout<<"Rollnum: ";
	s.displayrno();
	return 0;
}
