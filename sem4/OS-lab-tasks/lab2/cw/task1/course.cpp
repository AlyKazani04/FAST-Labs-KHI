#include "course.h"

Course::Course(const string t) : title(t)
{

}

string Course::getTitle() const
{
    return title;
}

void Course::AddStudent(Student& s)
{
    taking.emplace_back(&s);
}

void Course::AddTeacher(Teacher& t)
{
    teaching.emplace_back(&t);
}

void Course::display() const
{
    cout << "Title: " << title << endl;

    cout << "Students enrolled:\n";
    for(auto s : taking)
    {
        cout << "Name: " << s->getName() << endl;
        cout << "ID: " << s->getID() << endl << endl;
    }

    cout << "Teachers teaching:\n" << endl;
    for(auto t : teaching)
    {
        cout << "Name: " << t->getName() << endl;
        cout << "ID: " << t->getID() << endl << endl;
    }
}