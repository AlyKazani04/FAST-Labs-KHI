#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Exam
{
    private:
        char* studentName;
        char* examDate;
        int score;
    public:
        Exam(const char* name, const char* date, int scoreVal)
        {
            studentName = new char[strlen(name) + 1]; 
            strcpy(studentName, name);

            examDate = new char[strlen(date) + 1];
            strcpy(examDate, date);

            score = scoreVal;

            printDetails();
        }

        void printDetails()
        {
            cout << "Student Name: " << studentName << endl;
            cout << "Exam Date: " << examDate << endl;
            cout << "Score: " << score << endl;
        }

        ~Exam() 
        {
            delete[] studentName;
            delete[] examDate;
            cout << "Destructor called" << endl;
        }
};

int main()
{
    Exam exam1("Aly", "2/9/2025", 94);

    Exam exam2 = exam1; // shallow copy

    exam2.printDetails(); // running this manually to see the contents 
    // since no custom copy constructor exists to call this automatically

    // it has the same contents as exam1

    return 0;
}