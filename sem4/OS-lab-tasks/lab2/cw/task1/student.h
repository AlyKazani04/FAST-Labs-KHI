#pragma once

#include <iostream>
using namespace std;

#include "course.h"

class Course;

class Student
{
private:
    const string name;
    const int id;
    vector<Course*> enrolled;
public:
    Student(const string n, const int i);
    string getName() const;
    int getID() const;

    void AddCourse(Course& c);

    void display() const;
};
