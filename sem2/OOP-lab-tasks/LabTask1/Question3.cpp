#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

float CalculateBill(int units, float charge){
	float bill;
	bill = units * charge;
	return bill;
}

float ChargeCalc(int units){
	float charges;
	(units <= 0) ? charges = 0:
		(units < 200) ? charges = 16.20:
			(units >= 200 && units < 300) ? charges = 20.10:
				(units >= 300 && units < 500) ? charges = 27.10:
					charges = 35.90;;;;
	return charges;
}

void PrintBill(string id, string name, int units, float charges, float bill){
	cout<<"Customer ID: "<<id<<endl;
	cout<<"Customer Name: "<<name<<endl;
	cout<<"Units Consumed: "<<units<<endl;
	cout<<"Amount Charges @"<<charges<<" per unit: "<<bill<<endl;
	float scharge_amount = bill*0.15;
	cout<<"Surcharge Amount: "<<scharge_amount<<endl;
	float netamount = bill + scharge_amount;
	cout<<"Net Amount Paid by the Customer: "<<netamount<<endl;
}

int main(int argc, char* argv[]){
	string customer_id, customer_name;
	int units;
	float bill;
	
	cout<<"Enter ID: ";
	cin>>customer_id;	
	cout<<"Enter Name: ";
	cin>>customer_name;	
	cout<<"Enter Units: ";
	cin>>units;
	cout<<"_____________________"<<endl;
	bill = CalculateBill(units, ChargeCalc(units));
	PrintBill(customer_id, customer_name, units, ChargeCalc(units), bill);
	return 0;
}

