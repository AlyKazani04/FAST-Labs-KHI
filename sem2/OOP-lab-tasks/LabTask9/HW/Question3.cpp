#include <iostream>
#include <string>
using namespace std;

class Person {
    protected:
        string name;
        int id;
        float salary;

    public:
        virtual void getData() {
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Salary: ";
            cin >> salary;
        }

        virtual void displayData() {
            cout << "Name: " << name << "\nID: " << id << "\nSalary: " << salary << endl;
        }

        virtual void bonus() {
            float bonus = salary * 0.10f;
            cout << "Bonus: " << bonus << endl;
        }

        virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getData() override {
        cout << "[Admin Data Entry]\n";
        Person::getData();
    }

    void displayData() override {
        cout << "\n[Admin Data Display]\n";
        Person::displayData();
    }

    void bonus() override {
        float bonus = salary * 0.15f;
        cout << "Admin Bonus: " << bonus << endl;
    }
};

class Account : virtual public Person {
public:
    void getData() override {
        cout << "[Account Data Entry]\n";
        Person::getData();
    }

    void displayData() override {
        cout << "\n[Account Data Display]\n";
        Person::displayData();
    }

    void bonus() override {
        float bonus = salary * 0.12f;
        cout << "Account Bonus: " << bonus << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "[Master Data Entry]\n";
        Person::getData();
    }

    void displayData() override {
        cout << "\n[Master Data Display]\n";
        Person::displayData();
    }

    void bonus() override {
        float bonus = salary * 0.20f;
        cout << "Master Bonus: " << bonus << endl;
    }
};

int main() {
    Person* ptr;

    cout << "=== Admin ===\n";
    Admin adminObj;
    ptr = &adminObj;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << "\n=== Account ===\n";
    Account accountObj;
    ptr = &accountObj;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << "\n=== Master ===\n";
    Master masterObj;
    ptr = &masterObj;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    return 0;
}
