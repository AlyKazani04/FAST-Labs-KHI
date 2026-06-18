#pragma once

#include <iostream>
using namespace std;

#include "course.h"

class Course;

class Teacher
{
private:
    const string name;
    const int id;
    vector<Course*> teaching;
public:
    Teacher(const string name, const int id);
    string getName() const;
    int getID() const;

    void AddCourse(Course& c);

    void display() const;
};
