#include <bits/stdc++.h>
using namespace std;

struct Employee{
	string employee_id;
	string name;
	float salary;
};

struct Organisation{
	string organisation_name;
	string organisation_number;
	Employee emp;
};

int main(int argc, char** argv){
	Organisation org;
	org.emp.employee_id = "127";
	org.emp.name = "Linus Sebastian";
	org.emp.salary = 400000;
	org.organisation_name = "NU-Fast";
	org.organisation_number = "NUFAST123ABC";
	cout<<"The size of structure organisation : "<<sizeof(Organisation)<<endl;
	cout<<"Organisation Name: "<<org.organisation_name<<endl;
	cout<<"Organisation Number: "<<org.organisation_number<<endl;
	cout<<"Employee ID: "<<org.emp.employee_id<<endl;
	cout<<"Employee name: "<<org.emp.name<<endl;
	cout<<"Employee salary: "<<org.emp.salary<<endl;
	
	return 0;
}
