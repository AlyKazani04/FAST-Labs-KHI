#include <iostream>
using namespace std;

class Wallet{
	private:
		float balance;
		float transaction_limit;
		float dep_limit;
		float wit_limit;
	public:
		Wallet(float lim): balance(0), transaction_limit(lim) {
			dep_limit = transaction_limit;
			wit_limit = transaction_limit;
		}
		void deposit(float val){
			if(val > dep_limit){
				cout<<"Value greater than allowed."<<endl;
				cout<<"Allowed: "<<dep_limit<<endl;
				return;
			}
			balance += val;
			dep_limit -= val;
			cout<<"New Balance: "<<balance<<endl;
		}
		void withdraw(float val){
			if(val > wit_limit){
				cout<<"Value greater than allowed."<<endl;
				cout<<"Allowed: "<<wit_limit<<endl;
				return;
			}
			if(val > balance){
				cout<<"Value greater than balance."<<endl;
				cout<<"Balance: "<<balance<<endl;
				return;
			}
			balance -= val;
			wit_limit -= val;
			cout<<"Withdrawn: "<<val<<endl;
			cout<<"New Balance: "<<balance<<endl;
		}
		void newDay(){
			dep_limit = transaction_limit;
			wit_limit = transaction_limit;
			cout<<"Day has changed.\nLimits resetted."<<endl;
		}
};

static int idgenerate = 0;

class User{
	private:
		Wallet wallet;
		int id;
		string name;
	public:
		User(string n, float lim): wallet(lim), id(++idgenerate), name(n) {}
		void deposit(float val){
			wallet.deposit(val);
		}
		void withdraw(float val){
			wallet.withdraw(val);
		}
		void newDay(){
			wallet.newDay();
		}
};

int main(int argc, char**argv){
	User u("Name", 1000);
	u.deposit(999);
	u.deposit(2);
	u.newDay();
	u.deposit(600);
	
	u.withdraw(400);
	u.withdraw(700);
	u.newDay();
	u.withdraw(500);
	
	return 0;
}
