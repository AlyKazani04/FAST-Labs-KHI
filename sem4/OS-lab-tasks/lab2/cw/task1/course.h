#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "student.h"
#include "teacher.h"

class Student;
class Teacher;

class Course
{
private:
    string title;
    vector<Student*> taking;
    vector<Teacher*> teaching;
public:
    Course(const string t);
    string getTitle() const;

    void AddStudent(Student& s);
    void AddTeacher(Teacher& t);

    void display() const;
};