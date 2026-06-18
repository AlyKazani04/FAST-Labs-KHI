#include <iostream>
using namespace std;

class Person{
	private:
		string name;
		int age;
		string address;
	public:
		Person(string n, int age, string addr) : name(n), age(age), address(addr){}
		virtual string getname(){
			return name;
		}
		virtual int getage(){
			return age;
		}
		virtual string getaddr(){
			return address;
		}
		virtual void displayDetails(){
			cout<<"Name : "<<name<<endl;
			cout<<"Age : "<<getage()<<endl;
			cout<<"Address : "<<address<<endl;		
		}
};
class Student : public Person{
	private:
		int studentID;
		int grades[3];
	public:
		int getid(){
			return studentID;
		}
		Student(string name, int age, string address, int id, int grades) : Person(name, age, address), studentID(id){
			grades = {0};
		}
		void setgrade(int i, int grade){
			grades[i] = grade;
		}
		string getname() override{
			string name = Person::getname();
			return name;
		}
		string getaddr() override{
			string addr = Person::getaddr();
			return addr;
		}
		void calculateGPA(){
			float result=0;
			for(int i=0;i<3;i++){
				result  += grades[i];
			}
			result = (result/300)*4;
			cout<<"GPA "<<getname()<<": "<<result<<endl;
		}
		void displayDetails(){
			cout<<"Student ID : "<<getid()<<endl;
			cout<<"Name : "<<getname()<<endl;
			cout<<"Age : "<<getage()<<endl;
			cout<<"Address : "<<getaddr()<<endl;
			cout<<"Grades : "<<grades[0]<<", "<<grades[1]<<", "<<grades[2]<<endl;		
		}
		
};
class Teacher : public Person{
	private:
		int teacherID;
		string subject;
	public:
		Teacher(string name, int age, string address, int id, string sub) : Person(name, age, address), teacherID(id), subject(sub){}
		string getname() override{
			string name = Person::getname();
			return name;
		}
		int getage() override{
			int age = Person::getage();
			return age;
		}
		string getaddr() override{
			string addr = Person::getaddr();
			return addr;
		}
		void assignGrade(Student& s){
			int grade;
			cout<<"Student : "<<s.getname()<<endl;
			for(int i = 0; i < 3 ; i++){
				cout<<"Enter Grade "<<i+1<<" :";
				cin>>grade;
				s.setgrade(i, grade);
			}
		}
		void displayDetails() override{
			cout<<"Teacher ID : "<<teacherID<<endl;
			cout<<"Name : "<<getname()<<endl;
			cout<<"Age : "<<getage()<<endl;
			cout<<"Address : "<<getaddr()<<"\n"<<endl;
		}
};
int main(){
	Student s1("Aly", 20, "Clifton park", 11, {0});
	Student s2("Abrar", 19, "DHA park", 12, {0});
	Teacher t("Teach", 34, "FAST", 10, "CS");
	
	t.assignGrade(s1);
	t.assignGrade(s2);
	s1.calculateGPA();
	s2.calculateGPA();
	s1.displayDetails();
	s2.displayDetails();
	t.displayDetails();
	return 0;
}
