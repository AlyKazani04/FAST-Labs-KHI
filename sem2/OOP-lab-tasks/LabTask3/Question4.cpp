#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class Employee{
	string first_name;
	string last_name;
	double monthly_salary;
	public:
		Employee(){};
		Employee(string fname, string lname, double msalary){
			first_name = fname;
			last_name = lname;
			if(msalary <= 0){
				monthly_salary = 0;
			}
			else{
				monthly_salary = msalary;
			}
		}
		void display(){
			double yearly_S = monthly_salary * 12;
			cout<<"First Name: "<<first_name<<endl;
			cout<<"Last Name: "<<last_name<<endl;
			cout<<"Yearly Salary: "<<fixed<<setprecision(2)<<yearly_S<<endl;
		}
		void raise10(){
			monthly_salary*=1.1;
		}
};

int main(int argc, char** argv){
	Employee emp1("Aly", "Kazani", 100.5);
	Employee emp2("Asdh", "Last Name Here", 50);
	emp1.display();
	cout<<endl;
	emp2.display();
	cout<<endl;
	emp1.raise10();
	emp2.raise10();
	cout<<"Raised monthly salary by 10\%."<<endl<<endl;
	emp1.display();
	cout<<endl;
	emp2.display();
	
}
