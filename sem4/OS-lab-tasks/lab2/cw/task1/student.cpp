#include "student.h"

Student::Student(const string n, const int i) : name(n), id(i)
{
    
}

string Student::getName() const
{
    return name;
}

int Student::getID() const
{
    return id;
}

void Student::AddCourse(Course& c)
{
    enrolled.emplace_back(&c);
}

void Student::display() const
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;

    cout << "Courses:\n";
    for(Course* c : enrolled)
    {
        cout << "Title: " << c->getTitle() << endl;
    }
}