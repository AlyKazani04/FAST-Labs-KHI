#include <iostream>
#include <string>
using namespace std;

class Person{
	private:
		string name;
		int age;
	public:
		void setName(string s){
			name = s;
		}
		void setAge(int a){
			age = a;
		}
		string getName(){
			return name;
		}
		int getAge(){
			return age;
		}
		virtual void displayInfo(){
			cout<<"Name: "<<getName()<<endl;
			cout<<"Age: "<<getAge()<<endl;
		}
};

class Employee : public Person{
	private:
		int employeeID;
	public:
		void setID(int id){
			employeeID = id;
		}
		int getID(){
			return employeeID;
		}
		void displayInfo(){
			cout<<"Name: "<<getName()<<endl;
			cout<<"Age: "<<getAge()<<endl;
			cout<<"EmployeeID: "<<getID()<<endl;
		}
};

class Student : public Person{
	private:
		int studentID;
	public:
		void setID(int id){
			studentID = id;
		}
		int getID(){
			return studentID;
		}
		void displayInfo(){
			cout<<"Name: "<<getName()<<endl;
			cout<<"Age: "<<getAge()<<endl;
			cout<<"StudentID: "<<getID()<<endl;
		}
};

int main(){
	Person* Pptr;
	Employee E;
	Student S;

	E.setAge(100);
	E.setName("Emp1");
	E.setID(1);
	
	S.setAge(10);
	S.setName("St1");
	S.setID(2);
	
	cout<<"Employee:\n"<<endl;
	E.displayInfo();
	cout<<"\n";
	cout<<"Student:\n"<<endl;
	S.displayInfo();
	
	return 0;
}

