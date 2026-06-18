#include <iostream>
#include <vector>
using namespace std;

class Car{
	string name;
	int id;
	public:
		Car(string n, int i): name(n), id(i){
			cout<<"Car Created."<<endl;
		}
		string getname(){
			return name;
		}
		int getid(){
			return id;
		}
		~Car(){
			cout<<"Car Destroyed."<<endl;
		}
};

class Garage{
	vector<Car*> cars;
	public:
		Garage(){}
		void parkCar(Car* c){
			cars.push_back(c);
		}
		void listCars(){
			int i=0;
			for( Car *car : cars){
				cout<<"Car "<<i+1<<":"<<endl;
				cout<<"\t Name: "<<car->getname()<<endl;;
				cout<<"\t ID: "<<car->getid()<<endl;
				i++;
			}
		}
		~Garage(){
//			for( Car *car : cars){
//				delete car;
//			}
		}
};

int main(int argc, char** argv){
	
	Garage g;
	Car* car1 = new Car("Tesla", 100);
	Car* car2 = new Car("Swift", 101);
	
	g.parkCar(car1);
	g.parkCar(car2);
	
	g.listCars();
	
	delete car1;
	delete car2;
	
	return 0;
}