#include "course.h"
#include "student.h"
#include "teacher.h"

#include <iostream>
using namespace std;

void enrollStudent(Student& s, Course& c)
{
    s.AddCourse(c);
    c.AddStudent(s);
}

void assignTeacher(Teacher& t, Course& c)
{
    t.AddCourse(c);
    c.AddTeacher(t);
}

int main()
{
    Student s1("Aly", 512);
    Student s2("abc", 10);
    Student s3("def", 11);

    Teacher t("Mr.A", 1);

    Course c1("OS");
    Course c2("DSA");

    enrollStudent(s1, c1);
    enrollStudent(s1, c2);
    
    enrollStudent(s2, c1);
    enrollStudent(s2, c2);

    enrollStudent(s3, c2);

    assignTeacher(t, c1);
    assignTeacher(t, c2);

    cout << "Students:" << endl;
    s1.display();
    cout << endl;
    s2.display();
    cout << endl;
    s3.display();
    cout << endl;
    
    cout << "Teachers:" << endl;
    t.display();
    cout << endl;

    cout << "Courses:" << endl;
    c1.display();
    cout << endl;
    c2.display();

    return 0;
}