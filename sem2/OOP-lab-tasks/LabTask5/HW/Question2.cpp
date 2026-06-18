#include <bits/stdc++.h>
using namespace std;

class Car{
	public:
		mutable string engine;
		mutable int horsepower;
		mutable int seating_capacity;
		mutable int no_of_speakers;
		
		Car(string e, int h, int s, int n) : 
			engine(e), horsepower(h), seating_capacity(s), no_of_speakers(n){}
			
		void change(int seats, int spks, int hp, string e) const {
			seating_capacity = seats;
			no_of_speakers = spks;
			horsepower = hp;
			engine = e;
			
			cout<<"New engine: "<<engine<<endl;
			cout<<"New Horsepower: "<<horsepower<<endl;
			cout<<"New speakers: "<<no_of_speakers<<endl;
			cout<<"New seats: "<<seating_capacity<<endl;
		}
		void display(){
			cout<<"Car engine: "<<engine<<endl;
			cout<<"Horsepower: "<<horsepower<<endl;
			cout<<"Number of Speakers: "<<no_of_speakers<<endl;
			cout<<"Seating capacity: "<<seating_capacity<<endl;
		}
};

int main(int argc, char** argv){
	Car c1("v8", 1500, 4, 4);
	c1.display();
	cout<<endl;
	c1.change(1, 3, 2000, "v12");
	return 0;
}
