#include "teacher.h"

Teacher::Teacher(const string n, const int i) : name(n), id(i)
{

}

string Teacher::getName() const
{
    return name;
}

int Teacher::getID() const
{
    return id;
}

void Teacher::AddCourse(Course& c)
{
    teaching.emplace_back(&c);
}

void Teacher::display() const
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;

    cout << "Courses:\n";
    for(Course* c : teaching)
    {
        cout << "Title: " << c->getTitle() << endl;
    }
}