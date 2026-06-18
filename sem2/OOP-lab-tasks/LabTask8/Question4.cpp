#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person{
    protected:
        string name, id, address, phoneNumber, email;
    public:
        Person(string n, string i, string a, string p, string e):
            name(n), id(i), address(a), phoneNumber(p), email(e) {}
        virtual void displayinfo(){
            cout<<"Name: "<<name<<endl;
            cout<<"ID: "<<id<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Phone Number: "<<phoneNumber<<endl;
            cout<<"Email: "<<email<<endl;
        }
        virtual void updateInfo(string a, string p, string e){
            address = a;
            phoneNumber = p;
            email = e;
        }
};

class Student : public Person{
    private:
        vector<string> coursesEnrolled;
        float gpa;
        int enrollmentYear;
    public:
        Student(string n, string i, string a , string p, string e, float g, int year):
            Person(n, i, a, p, e), gpa(g), enrollmentYear(year) {}
        void enrollCourse(string course){
            coursesEnrolled.push_back(course);
        }
        string getName(){
            return name;
        }
        void displayinfo() override{
            Person::displayinfo();
            cout<<"Enrollment Year: "<<enrollmentYear<<endl;
            cout<<"GPA: "<<gpa<<endl;
            cout<<"Courses Enrolled: ";
            for(auto& c: coursesEnrolled){
                cout<<"\t"<<c<<endl;
            }
            cout<<endl;
        }
};

class Professor : public Person{
    private:
        string department;
        vector<string> coursesTaught;
        float salary;
    public:
        Professor(string n, string i, string a , string p, string e, string d, float sal):
            Person(n, i, a, p, e), department(d), salary(sal) {}
        void addCourse(string course){
            coursesTaught.push_back(course);
        }
        void displayinfo() override{
            Person::displayinfo();
            cout<<"Department: "<<department<<endl;
            cout<<"Salary: "<<salary<<endl;
            cout<<"Courses Taught: ";
            for(auto& c: coursesTaught){
                cout<<"\t"<<c<<endl;
            }
            cout<<endl;
        }
};

class Staff : public Person{
    private:
        string department, position;
        float salary;
    public:
        Staff(string n, string i, string a , string p, string e, string d, string pos, float sal):
            Person(n, i, a, p, e), department(d), position(pos), salary(sal) {}
        void displayinfo() override{
            Person::displayinfo();
            cout<<"Department: "<<department<<endl;
            cout<<"Position: "<<position<<endl;
            cout<<"Salary: "<<salary<<endl;
            cout<<endl;
        }
};

class Course{
    private:
        string courseID, courseName, schedule;
        int credits;
        string instructor;
        vector<Student*> enrolledStudents;
    public:
        Course(string id, string name, int cr, string ins, string sched):
            courseID(id), courseName(name), credits(cr), instructor(ins), schedule(sched) {}
        void registerStudent(Student* std){
            enrolledStudents.push_back(std);
        }
        void displayCourseInfo(){
            cout<<"Course ID: "<<courseID<<endl;
            cout<<"Course Name: "<<courseName<<endl;
            cout<<"Credits: "<<credits<<endl;
            cout<<"Schedule: "<<schedule<<endl;
            cout<<"Instructor: "<<instructor<<endl;
            cout<<"Enrolled Students: "<<endl;
            for(Student* s: enrolledStudents){
                cout<<"\t"<<s->getName()<<endl;
            }
        }
};

int main(){
    Student s1("Ash", "S123", "Route 1, Kanto", "123-456-7890", "ash@pokemail.com", 2022, 3.8);
    Professor p1("Professor Oak", "P456", "Route 5, Kanto", "987-654-3210", "oak@pokemail.com", "Poke Battles", 90000);
    Staff st1("Jenny", "ST789", "Route 3, Kanto", "111-222-3333", "jenny@pokecenter.com", "Pokemon Health", "Receptionist", 40000);
    
    Course c1("PB101", "Intro to Pokemon Battles", 3, "Professor Oak", "MWF 10AM-1PM");
    c1.registerStudent(&s1);
    
    cout << "--- Student Info ---\n";
    s1.displayinfo();
    cout << "\n--- Professor Info ---\n";
    p1.displayinfo();
    cout << "\n--- Staff Info ---\n";
    st1.displayinfo();
    cout << "\n--- Course Info ---\n";
    c1.displayCourseInfo();


    return 0;
}