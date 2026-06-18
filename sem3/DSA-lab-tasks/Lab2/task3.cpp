#include <iostream>
using namespace std;

class Student{
    private:
        float marks[5];
    public:
        Student(){ 
            for(int i = 0; i < 5; i++){
                marks[i] = 0.f;
            }
        }

        Student& operator=(const Student& other){
            if(this != &other){
                for(int i = 0; i < 5; i++){
                    marks[i] = other.marks[i];
                }
            }

            return *this;
        }

        void fill(){
            cin >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
        }
        float Sum(){
            float sum = 0.f;

            for(int i = 0; i <5; i++){
                sum += marks[i];
            }

            return sum;
        }
};

class Department{
    private:
        Student* students;
        int numStudents;
    public: 
        Department(){
            numStudents = 0;
            students = nullptr;
        }

        Department(int n){
            numStudents = n;
            students = new Student[n];
            for(int i = 0; i < numStudents; i++){
                cout << "Student " << i + 1 << " Marks(5 floats): ";
                students[i].fill();
            }
        }

        Department(const Department& other){
            numStudents = other.numStudents;
            students = new Student[numStudents];

            for(int i = 0; i < numStudents; i++){
                students[i] = other.students[i];
            }
        }
        
        Department& operator=(const Department& other){
            if(this != &other){
                delete[] students;
                numStudents = other.numStudents;
                students = new Student[numStudents];

                for(int i = 0; i < numStudents; i++){
                    students[i] = other.students[i];
                }
            }

            return *this;
        }

        float Lowest(){
            float lowest = students[0].Sum();

            for(int i = 1; i < numStudents; i++){
                float sum = students[i].Sum();

                if(sum < lowest){
                    lowest = sum;
                }
            }

            return lowest;
        }

        float Highest(){
            float highest = students[0].Sum();

            for(int i = 1; i < numStudents; i++){
                float sum = students[i].Sum();

                if(sum > highest){
                    highest = sum;
                }
            }

            return highest;
        }

        float Average(){
            float total = 0.f;

            for(int i = 0; i < numStudents; i++){
                
                total += students[i].Sum();
            }

            return total / numStudents;
        }

        void displayAsRow(){
            for(int i = 0; i < numStudents; i++){
                cout << students[i].Sum() << " ";
            }
        }

        ~Department(){
            delete[] students;
        }
};

class University{
    private:
        Department* departments;
        int numDepartments;
    public:
        University(int n){
            numDepartments = n;
            departments = new Department[n];

            for(int i = 0; i < numDepartments; i++){
                int numStudents;
                cout << "Enter number of Students in Department " << i + 1 <<": ";
                cin >> numStudents;
                departments[i] = Department(numStudents);
            }
        }

        University(const University& other){
            numDepartments = other.numDepartments;
            departments = new Department[numDepartments];
            
            for(int i = 0 ; i < numDepartments; i++){
                departments[i] = other.departments[i];
            }
        }

        void printHighests(){
            for(int i = 0; i < numDepartments; i++){
                cout << "Department " << i + 1 << " \'s Highest: " << departments[i].Highest() << endl;
            }
        }

        void printLowests(){
            for(int i = 0; i < numDepartments; i++){
                cout << "Department " << i + 1 << " \'s Lowest: " << departments[i].Lowest() << endl;
            }
        }

        void printAverages(){
            for(int i = 0; i < numDepartments; i++){
                cout << "Department " << i + 1 << " \'s Average: " << departments[i].Average() << endl;
            }
        }

        void displayAsArray(){
            for(int i = 0; i < numDepartments; i++){
                cout << "Department " << i + 1 << ": ";
                departments[i].displayAsRow();
                cout << endl;
            }
        }
        ~University(){
            delete[] departments;
        }
};

int main(){
    int numDepartments;

    cout << "Enter number of Departments: ";
    cin >> numDepartments;

    University uni(numDepartments);

    uni.printHighests();
    uni.printLowests();
    uni.printAverages();

    cout << "Departments as Array: " << endl;
    uni.displayAsArray();

    return 0;
}