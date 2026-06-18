#include <iostream>
using namespace std;

class BankAccount
{
    private:
        float balance;
    public:
        void printBalance()
        {
            cout << "Balance: " << balance << endl;
        }

        void deduct(float amount)
        {
            balance -= amount;
            cout << "Deducted " << amount << endl;
        }

        BankAccount()
        {
            balance = 0.f;
            cout << "Default Constructor Called" << endl;    
        }

        BankAccount(float initBal)
        {
            balance = initBal;
            cout << "Parameterized Constructor Called" << endl;
            cout << "Initial ";
            printBalance();
        }

        BankAccount(const BankAccount& other)
        {
            balance = other.balance;
            cout << "Copy Constructor Called" << endl;
            cout << "Copied ";
            printBalance();
        }
};

int main()
{
    
    BankAccount account1; // default

    BankAccount account2(1000); // parameterized

    BankAccount account3(account2); // copy

    account3.deduct(200);

    cout << "Account 3's ";
    account3.printBalance();

    cout << "Account 2's ";
    account2.printBalance();

    cout << "Account 1's ";
    account1.printBalance();

    return 0;
}
