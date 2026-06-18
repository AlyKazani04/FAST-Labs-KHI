#include <bits/stdc++.h>
using namespace std;

class Account{
	double balance;
	public:
		void addBalance(double val){
			balance += val;
		}
		void withdraw(double val){
			balance -= val;
		}
		double getBalance(){
			return balance;
		}
};

int main(int argc, char** argv){
	Account a;
	a.addBalance(10000.4);
	cout<<fixed<<setprecision(2)<<a.getBalance()<<endl;
	a.withdraw(434.7);
	cout<<fixed<<setprecision(2)<<a.getBalance()<<endl;
	return 0;
}