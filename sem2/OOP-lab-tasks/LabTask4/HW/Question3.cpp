#include <bits/stdc++.h>
using namespace std;

class Invoice{
	string partnumber;
	string partdescription;
	int quantity;
	double price;
	public:
		Invoice(){
			partnumber = "Unknown";
			partdescription = "No description";
			quantity = 0;
			price = 0.0;
		}
		Invoice(string num, string des, int quan, double p){
			partnumber = num;
			partdescription = des;
			quantity = quan;
			price = p;
		}
		double getInvoiceAmount(){
			if(quantity < 0)	quantity = 0;
			if(price < 0)	price = 0;
			return quantity * price;
		}
		void getDetails(){
			cout<<"partnumber: "<<partnumber<<endl;
			cout<<"partdescription: "<<partdescription<<endl;
			cout<<"quantity: "<<quantity<<endl;
			cout<<"price: "<<fixed<<setprecision(1)<<price<<endl;
		}
};

int main(int argc, char** argv){
	Invoice a;
	a.getDetails();
	cout<<endl;
	Invoice i("Part 1", "Screw", 3, 10);
//	cout<<fixed<<setprecision(2)<<i.getInvoiceAmount()<<endl;
	i.getDetails();
	return 0;
}
