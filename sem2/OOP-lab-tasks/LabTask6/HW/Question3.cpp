#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
	int id;
	string name;

public:
	void getStudentDetails() {
		cout<<"Enter Student ID: ";
		cin>>id;
		cin.ignore(); 
		cout<<"Enter Student Name: ";
		getline(cin, name);
	}
	
	void displayStudentDetails() const {
		cout<<"\nStudent ID: "<<id<<"\nStudent Name: "<<name<<"\n";
	}
};

class Marks : public Student {
protected:
	int marks_oop, marks_pf, marks_ds, marks_ee;

public:
	void getMarks() {
		cout<<"Enter marks for OOP: ";
		cin>>marks_oop;
		cout<<"Enter marks for PF: ";
		cin>>marks_pf;
		cout<<"Enter marks for DS: ";
		cin>>marks_ds;
		cout<<"Enter marks for EE: ";
		cin>>marks_ee;
	}
	
	void displayMarks() const {
		cout<<"\nMarks Obtained:\n";
		cout<<"OOP: "<<marks_oop<<"\nPF: "<<marks_pf<<"\nDS: "<<marks_ds<<"\nDB: "<<marks_ee<<"\n";
	}
};

class Result : public Marks {
private:
	int total_marks;
	double avg_marks;

public:
	void calculateResult(){
		total_marks = marks_oop + marks_pf + marks_ds + marks_ee;
		avg_marks = total_marks / 4;
	}
	
	void display(){
		displayStudentDetails();
		displayMarks();
		cout<<"\nTotal Marks: "<<total_marks;
		cout<<"\nAverage Marks: "<<avg_marks<<"\n";
	}
};

int main(int argc, char** args){
	Result s1;
	s1.getStudentDetails();
	s1.getMarks();
	s1.calculateResult();
	s1.display();
	return 0;
}
