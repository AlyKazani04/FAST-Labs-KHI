#include <bits/stdc++.h>
using namespace std;

float CalcTotal(float priceA, float priceC, int numA, int numC){
	float total;
	total = priceA * numA + priceC * numC;
	return total;
}

float CalculateDonation(float total, float percent){
	return total * (float)percent/100;
}

int main(int argc, char* argv[]){
	string name;
	float price_A, price_C, donation_percent, gross, netsales;
	int sold_A, sold_C;
	cout<<"Enter Movie Name: ";
	getline(cin, name);
	cout<<"Enter Adult Ticket Price: ";
	cin>>price_A;
	cout<<"Enter Child Ticket Price: ";
	cin>>price_C;
	cout<<"Enter Number of Adult Tickets Sold: ";
	cin>>sold_A;
	cout<<"Enter Number of Child Tickets Sold: ";
	cin>>sold_C;
	cout<<"Enter the Percentage of Sales to Donate: ";
	cin>>donation_percent;
	gross = CalcTotal(price_A, price_C, sold_A, sold_C);
	netsales = gross - CalculateDonation(gross, donation_percent);
	int tickets_sold = sold_A + sold_C;
	cout<<endl;
	cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	cout<<"Movie Name: "<<right<<setw(39)<<name<<endl;
	cout<<"Number of Tickets Sold: "<<right<<setw(15)<<tickets_sold<<endl;
	cout<<"Gross Amount: "<<right<<setw(24)<<"$ "<<fixed<<setprecision(2)<<gross<<endl;
	cout<<"Percentage of Gross Amount Donated: "<<fixed<<setprecision(2)<<donation_percent<<"%"<<endl;
	cout<<"Amount Donated: "<<right<<setw(22)<<"$ "<<fixed<<setprecision(2)<<CalculateDonation(gross, donation_percent)<<endl;
	cout<<"Net Sale: "<<right<<setw(28)<<"$ "<<fixed<<setprecision(2)<<netsales<<endl;
	return 0;
}

