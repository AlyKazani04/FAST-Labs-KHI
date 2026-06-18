#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

static int accountIDS = 0;

class Account{
    protected:
        int accountNumber;
        float balance;
        string accountHolderName;
        string accountType; 
        vector<string> transactions;
    public:
        Account(string name, float initial) : accountHolderName(name), balance(initial) {
            accountNumber = accountIDS++;
            transactions.push_back("Account created with initial balance of " + to_string(initial));
        }
        void deposit(float val){
            if(val > 0){
                balance += val;
                transactions.push_back("Deposited " + to_string(val) + " into account.");
                cout<<fixed<<setprecision(2)<<"Deposited "<<val<<" into account."<<endl;
            } else {
                cout<<"Invalid Deposit Amount."<<endl;
            }
        }
        virtual void withdraw(float val){
            if(val > 0 && val < balance){
                balance -= val;
                transactions.push_back("Withdrawn " + to_string(val) + " from account.");
                cout<<fixed<<setprecision(2)<<"Withdrawn "<<val<<" from account."<<endl;
            } else{
                cout<<"Insufficient funds"<<endl;
            }
        }
        virtual void calculateInterest(){
            // balance += balance * interest_rate/100;
        }
        virtual void printStatement(){
            getAccountInfo();
            cout<<"Transactions: "<<endl;
            for(const auto& transaction : transactions){
                cout<<" - "<<transaction<<endl;
            }
        }
        void getAccountInfo(){
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Account Holder Name: "<<accountHolderName<<endl;
            cout<<"Account Type: "<<accountType<<endl;
            cout<<fixed<<setprecision(2)<<"Account Balance: "<<balance<<endl;
        }
        ~Account(){}
};

class SavingsAccount : public Account{
    private:
        float interestRate;
        float minimumBalance;
    public:
        SavingsAccount(string name, float initial, float rate, float minBal) : 
            Account(name, initial), interestRate(rate), minimumBalance(minBal) {
                accountType = "Savings";
            }
        void withdraw(float val) override{
            if( (balance - val) >= minimumBalance){
                Account::withdraw(val);
            } else{
                cout<<"Insufficient funds"<<endl;
            }
        }
        void calculateInterest() override{
            float interest = balance * interestRate/100;
            balance += interest;
            transactions.push_back("Interest Added: " + to_string(interest) + " to account." + "New Balance: " + to_string(balance));
            cout<<fixed<<setprecision(2)<<"Interest Added: "<<interest<<endl;
            cout<<fixed<<setprecision(2)<<"New Balance: "<<balance<<endl;

        }
        void printStatement() override{
            getAccountInfo();
            cout<<fixed<<setprecision(2)<<"Minimum Balance: "<<minimumBalance<<endl;
            cout<<fixed<<setprecision(2)<<"Interest Rate: "<<interestRate/100<<"%"<<endl;
            cout<<"Transactions: "<<endl;
            for(const auto& transaction : transactions){
                cout<<" - "<<transaction<<endl;
            }
        }
        ~SavingsAccount(){}
};

class FixedDepositAccount : public Account{
    private:
        string maturityDate;
        float fixedInterestRate;
    public:
        FixedDepositAccount(string name, float initial, float rate, string maturity) : 
            Account(name, initial), fixedInterestRate(rate), maturityDate(maturity) {
                accountType = "FixedDeposit";
            }
        void withdraw(float val) override{
            cout<<"Withdrawals not allowed before maturity date"<<endl;
        }
        void calculateInterest() override{
            float interest = balance * fixedInterestRate/100;
            balance += interest;
            cout<<fixed<<setprecision(2)<<"Fixed Deposit Interest Added: "<<interest<<endl;
            cout<<fixed<<setprecision(2)<<"New Balance: "<<balance<<endl;
        }
        void printStatement() override{
            getAccountInfo();
            cout<<fixed<<setprecision(2)<<"Fixed Interest Rate: "<<fixedInterestRate/100<<"%"<<endl;
            cout<<"Maturity Date: "<<maturityDate<<endl;
            cout<<"Transactions: "<<endl;
            for(const auto& transaction : transactions){
                cout<<" - "<<transaction<<endl;
            }
        }
        ~FixedDepositAccount(){}
};

class CheckingAccount : public Account{
    public:
        CheckingAccount(string name, float initial) : 
            Account(name, initial) {
            accountType = "Checking";
        }
        void calculateInterest(){
            cout<<"Checking accounts do not earn interest."<<endl;
        }
        ~CheckingAccount(){}
};

int main(){
    SavingsAccount s("Aly", 1000, 5, 150);
    FixedDepositAccount fda("Alex", 800, 3, "18/6/2027");
    CheckingAccount ca("Charles", 500);

    s.deposit(600);
    s.calculateInterest();
    s.withdraw(1500);
    s.printStatement();

    fda.deposit(200);
    fda.withdraw(100.2);
    fda.calculateInterest();
    fda.printStatement();

    ca.deposit(501);
    ca.calculateInterest();
    ca.withdraw(100);
    ca.printStatement();


    return 0;
}