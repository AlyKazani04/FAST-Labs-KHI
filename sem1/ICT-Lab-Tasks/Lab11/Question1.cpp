#include <iostream>
using namespace std;

class Animal{
	private:
		string name;
		int age;
	public:
		void setName(string s){
			name = s;
		}
		void setAge(int a){
			age = a;
		}
		string getName(){
			return name;
		}
		int getAge(){
			return age;
		}
		virtual void displayInfo(){
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
		}
};
class Mammal : public Animal{
	public:
		void feedBaby(){
			cout<<"Feeding baby mammal."<<endl;
		}
};
class Bird : public Animal{
	public:
		void layEgg(){
			cout<<"Laying an egg."<<endl;
		}
};
class Reptile : public Animal{
	public:
		void shedSkin(){
			cout<<"Shedding skin."<<endl;
		}
};
int main(){
	Mammal M;
	M.setName("Mam");
	M.setAge(1);
	Bird B;
	B.setName("Bir");
	B.setAge(2);
	Reptile R;
	R.setName("Rep");
	R.setAge(3);
	
	cout<<"Mammal:"<<endl;
	M.displayInfo();
	M.feedBaby();
	cout<<"Bird:"<<endl;
	B.displayInfo();
	B.layEgg();
	cout<<"Reptile:"<<endl;
	R.displayInfo();
	R.shedSkin();
	
	return 0;
}
