#include <iostream>
using namespace std;

int numberOfStudents()
{
    int students;
    cout << "Enter the number of Students: ";
    cin >> students;

    return students;
}

int numberOfSubjects()
{
    int subjects;
    cout << "Enter the number of Subjects to check: ";
    cin >> subjects;

    return subjects;
}

void enterStudentMarks(float* marks, int subjects)
{
    for(int i = 0; i < subjects; i++)
    {
        cout << "Enter Marks for subject " << i + 1 << ": ";
        cin >> marks[i];
    }
}

float totalMarks(const float* marks, int subjects)
{
    float total = 0;
    for(int i = 0; i < subjects; i++)
    {
        total += marks[i];
    }

    return total;
}

float averageMarks(const float* marks, int subjects)
{
    float sum = 0;
    for(int i = 0; i < subjects; i++)
    {
        sum += marks[i];
    }
    
    return sum/subjects;
}

int main()
{
    int students = numberOfStudents();

    float** marks = new float*[students];

    int subjects = numberOfSubjects();

    for(int i = 0; i < students; i++)
    {
        marks[i] = new float[subjects];
    }

    for(int i = 0; i < students; i++)
    {
        enterStudentMarks(marks[i], subjects);
    }

    float* totals = new float[students];
    float* averages = new float[students];

    for(int i = 0; i < students; i++)
    {
        totals[i] = totalMarks(marks[i], subjects);

        averages[i] = averageMarks(marks[i], subjects);

        cout << "Total for Student " << i + 1 << ": " << totals[i] << endl;

        cout << "Average for Student " << i + 1 << ": " << averages[i] << endl;
    }

    float highest = 0;
    int highestindex = 0;
    for(int i = 0; i < students; i++)
    {
        if(totals[i] > highest)
        {
            highest = totals[i];
            highestindex = i;
        }
    }

    cout << "Topper is Student " << highestindex + 1 << " with Total : " << highest << endl;

    
    
    for(int i = 0; i < students; i++)
    {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] totals;
    delete[] averages;
    
    return 0;
}