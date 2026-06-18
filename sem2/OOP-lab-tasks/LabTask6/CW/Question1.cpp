#include <iostream>
using namespace std;

class BankAccount{
	protected:
		bool isActive = true;
		string accountnumber;
		float balance = 0;
	public:
		BankAccount(string accnum) : accountnumber(accnum) {}
		void activeChange(){
			(isActive == true) ? isActive = false :
				(isActive == false) ? isActive = true : true;
		}
		virtual void deposit(float val){
			balance += val;
			cout<<"Deposited: "<<val<<endl;
			cout<<"New Balance: "<<balance<<endl;
		}
		virtual void withdraw(float val){
			if(balance > val){
				balance -= val;
				cout<<"Withdrawn: "<<val<<endl;
				cout<<"New Balance: "<<balance<<endl;
			}
		}
		string getStatus(){
			if(isActive == true){
				return "Active";
			} else{
				return "Inactive";
			}
		}
		string getaccnumber(){
			return accountnumber;
		}
};

class SavingAccount : public BankAccount{
	private:
		float interest_mon;
	public:
		SavingAccount(string accnum, float inter_m) : BankAccount(accnum), interest_mon(inter_m) {}
		void applyinterest(){
			float interest = balance * interest_mon;
			cout<<"Balance: "<<balance<<endl;
			balance += interest;
			cout<<"Balance after Interest: "<<balance<<endl;
		}
		void display(){
			cout<<"Saving Account ID: "<<accountnumber<<endl;
			cout<<"Balance: "<<balance<<endl;
			cout<<"Monthly Interest: "<<interest_mon<<endl;
			cout<<"Status: "<<getStatus()<<endl;
		}
};

class CheckingAccount : public BankAccount{
	private:
		float overdraft = 0;
		float limit = 10000;
	public:
		CheckingAccount(string accnum) : BankAccount(accnum) {}
		float getlimit(){
			return limit;
		}
		virtual void withdraw(float val){
			if(val > balance){
				float required = val - balance;
				if( required <= limit ){
					overdraft += required;
					limit -= required;
					balance = 0;
					cout<<"Withdrawn: "<<val<<endl;
					cout<<"New Balance: "<<balance<<endl;
					cout<<"Limit Remaining: "<<limit<<endl;
				}
				else{
					cout<<"Insufficient balance and overdraft condition not met."<<endl;
					return;
				}
			}
			else{
				balance -= val;
			}
		}
		void changelimit(float val){
			limit = val;
		}
		virtual void deposit(float val){
			if(overdraft > 0){
				float repay = (val < overdraft) ? val : overdraft;
				overdraft -= repay;
				limit += repay;
				val -= repay;
			}
			balance += val;
			cout<<"Deposited: "<<val<<endl;
			cout<<"New Balance: "<<balance<<endl;
		}
		void display(){
			cout<<"Checking Account ID: "<<accountnumber<<endl;
			cout<<"Balance: "<<balance<<endl;
			cout<<"Overdraft: "<<overdraft<<endl;
			cout<<"Limit Remaining: "<<limit<<endl;
			cout<<"Status: "<<getStatus()<<endl;
		}
};

class BusinessAccount : public BankAccount{
	private:
		float tax_percentage;
	public:
		BusinessAccount(string accnum, float t) : BankAccount(accnum), tax_percentage(t) {}
		void deposit(float val) override{
			if(val > 0){
				cout<<"Value deposited: "<<val<<endl;
				float tax = val * tax_percentage;
				cout<<"Value after Tax: "<<val-tax<<endl;
				balance += val - tax;
				cout<<"New Balance: "<<balance<<endl;
			} else{
				cout<<"Invalid Deposit Amount"<<endl;
			}
		}
		void display(){
			cout<<"Checking Account ID: "<<accountnumber<<endl;
			cout<<"Balance: "<<balance<<endl;
			cout<<"Tax Rate: "<<tax_percentage*100<<"\%"<<endl;
			cout<<"Status: "<<getStatus()<<endl;
		}
};

class Customer{
	private:
		int id;
		SavingAccount savingacc;
		CheckingAccount checkingacc;
	public:
		Customer(int i, string snum, float int_m, string cnum) : id(i), savingacc(snum, int_m), checkingacc(cnum) {}
		void depositSav(float val){
			savingacc.deposit(val);
		}
		void depositChe(float val){
			checkingacc.deposit(val);
		}
		void withdrawSav(float val){
			savingacc.withdraw(val);
		}
		void withdrawChe(float val){
			checkingacc.withdraw(val);
		}
		void display(){
			cout<<"Customer ID: "<<id<<endl;
			savingacc.display();
			checkingacc.display();
		}
		void applyinterest(){
			savingacc.applyinterest();
		}
		SavingAccount& getSAcc(){
			return savingacc;
		}
		CheckingAccount& getCAcc(){
			return checkingacc;
		}
};

class Employee{
	protected:
		int id;
		BusinessAccount B_account;
		SavingAccount* savingptr = nullptr;
		CheckingAccount* checkingptr = nullptr;
	public:
		Employee(int i, string acnum, float tax_p) : B_account(acnum, tax_p), id(i) {}
		void assignSAccount(SavingAccount& s){
			savingptr = &s;
		}
		void assignCAccount(CheckingAccount& c){
			checkingptr = &c;
		}
		void deposit(float val){
			B_account.deposit(val);
		}
		void withdraw(float val){
			B_account.withdraw(val);
		}
		void display(){
			cout<<"Employee ID: "<<id<<endl;
			B_account.display();
			cout<<endl;
			cout<<"Working on Saving Account: "<<endl;
			if(savingptr == nullptr){
				cout<<"None"<<endl;
			} else{
				savingptr->display();
			}
			cout<<endl<<"Working on Checking Account: "<<endl;
			if(checkingptr == nullptr){
				cout<<"None"<<endl;
			} else{
				checkingptr->display();
			}
		}
};

class Teller : public Employee{
	public:
		Teller(int i, string acnum, float tax_p) : Employee(i, acnum, tax_p) {}
		void freezeSAcc(){
			savingptr->activeChange();
			cout<<"Saving Account "<<savingptr->getaccnumber()<<" frozen."<<endl;
		}
		void freezeCAcc(){
			checkingptr->activeChange();
			cout<<"Checking Account "<<checkingptr->getaccnumber()<<" frozen."<<endl;
		}
		void depositS(float val){
			savingptr->deposit(val);
			cout<<"Deposited "<<val<<" in "<<savingptr->getaccnumber()<<endl;
		}
		void depositC(float val){
			checkingptr->deposit(val);
			cout<<"Deposited "<<val<<" in "<<checkingptr->getaccnumber()<<endl;;
		}
		void withdrawS(float val){
			savingptr->withdraw(val);
		}
		void withdrawC(float val){
			checkingptr->withdraw(val);
		}
};

class Manager : public Employee{
	public:
		Manager(int i, string acnum, float tax_p) : Employee(i, acnum, tax_p) {}
	void overrideLimit(float val){
		checkingptr->changelimit(val);
		cout<<"New limit: " <<checkingptr->getlimit()<<endl;
	}
};
int main(int argc, char** argv){
	Customer c1(101, "123", 0.11, "234" );
	
	c1.depositChe(2000);
	c1.depositSav(5000);
	c1.applyinterest();
	c1.withdrawChe(110);
	c1.withdrawSav(1000);
	
	cout<<endl;
	c1.display();
	
	cout<<endl;
	Teller t1(1, "001", 0.05);
	t1.deposit(35000);
	t1.assignCAccount(c1.getCAcc());
	t1.assignSAccount(c1.getSAcc());
	t1.freezeCAcc();
	cout<<endl;
	t1.display();
	
	cout<<endl;
	Manager m1(2, "002", 0.1);
	m1.deposit(170000);
	cout<<endl;
	m1.assignCAccount(c1.getCAcc());
	m1.overrideLimit(15000);
	c1.withdrawChe(3000);
	cout<<endl;
	m1.display();
	
	return 0;
}