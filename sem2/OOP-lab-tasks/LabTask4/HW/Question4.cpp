#include <bits/stdc++.h>
#include <string>
using namespace std;

class books{
	string author;
	string title;
	float price;
	string publisher;
	int stock;
	public:
		books(){
			author = "Unknown";
			title = "Unknown";
			price = 0;
			publisher = "Unknown";
			stock = 0;
		}
		books(string at, string ti, float pr, string pub, int st){
			author = at;
			title = ti;
			price = pr;
			publisher = pub;
			stock = st;
		}
		string gettitle(){
			return title;
		}
		string getauthor(){
			return author;
		}
		void display(){
			cout<<"Title: "<<title<<endl;
			cout<<"Author: "<<author<<endl;
			cout<<"Publisher: "<<publisher<<endl;
			cout<<"Price: "<<fixed<<setprecision(1)<<price<<endl;
			cout<<"Stock: "<<stock<<endl;
		}
		void Availability(int num){
			if(stock >= num){
				cout<<"Total Cost: "<<fixed<<setprecision(2)<<price*num<<endl;
			}
			else{
				if(stock == 0)
					cout<<"Required copies not in stock."<<endl;
				else
					cout<<"Not enough copies in stock."<<endl;
			}
			cout<<endl;
		}
};

void isbookavailable(string tcheck, string atcheck, books arr[], int size){
	int num;
	for(int i = 0; i < size; i++){
		if(tcheck.compare(arr[i].gettitle()) == 0 && atcheck.compare(arr[i].getauthor()) == 0){
			arr[i].display();
			cout<<endl<<"Enter number of copies needed: ";
			cin>>num;
			arr[i].Availability(num);
			return;
		}
	}
	cout<<"Book not found."<<endl;
}



int main(int argc, char** argv){
	books bookarr[5] = {books("Aly", "Title1", 150.54, "Publish1", 4),
						books("Jeff", "Title2", 100.34, "Publish2", 0)
	};
	int size = 5;
	isbookavailable("Title1", "Aly", bookarr, 5);
	isbookavailable("Harry Potter", "JK Rowling", bookarr, 5);
	return 0;
}
