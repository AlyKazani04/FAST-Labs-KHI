#include <iostream>
using namespace std;

class Person{
    protected:
        int employeeID;
    public:
        Person(){}
        Person(int id) : employeeID(id) {}
        virtual void getData(){
            cout<<"Enter Employee ID: ";
            cin>>employeeID;
        }
        virtual void displayData(){
            cout<<"Employee ID: "<<employeeID<<endl;
        }
};

class Admin : public Person{
    private:
        string name;
        float monthly_income;
    public:
        Admin(){}
        Admin(int id, string n, float inc): Person(id), name(n), monthly_income(inc) {}
        void bonus(){
            float bonus = 0.05 * monthly_income * 12; // 5% of annual income
            cout<<"Bonus: "<<bonus<<endl;
        }
        void getData(){
            Person::getData();
            cin.ignore();
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Monthly Income: ";
            cin>>monthly_income;
        }
        void displayData() override{
            Person::displayData();
            cout<<"Name: "<<name<<endl;
            cout<<"Monthly Income: "<<monthly_income<<endl;
            bonus();
        }
};

class Accounts : public Person{
    private:
        string name;
        float monthly_income;
    public:
        Accounts(){}
        Accounts(int id, string n, float inc): Person(id), name(n), monthly_income(inc) {}
        void bonus(){
            float bonus = 0.05 * monthly_income * 12; // 5% of annual income
            cout<<"Bonus: "<<bonus<<endl;
        }
        void getData(){
            Person::getData();
            cin.ignore();
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Monthly Income: ";
            cin>>monthly_income;
        }
        void displayData() override{
            Person::displayData();
            cout<<"Name: "<<name<<endl;
            cout<<"Monthly Income: "<<monthly_income<<endl;
            bonus();
        }
};

int main(){
    Admin admin;
    Accounts account;

    admin.getData();
    account.getData();

    cout<<endl<<endl;
    admin.displayData();
    cout<<endl;
    account.displayData();

    return 0;
}