#include <iostream>
using namespace std;

class Engine{
	bool isRunning;
	public:
		Engine(){
			cout<<"Engine Created."<<endl;
		}
		void start(){
			cout<<"Engine started."<<endl;
			isRunning = true;
		}
		void stop(){
			cout<<"Engine stopped."<<endl;
			isRunning = false;
		}
		~Engine(){
			cout<<"Engine Destroyed."<<endl;
		}
};

class Car{
	Engine engine;
	public:
		Car(){
			cout<<"Car Created."<<endl;
		}
		void startCar(){
			engine.start();
		}
		void stopCar(){
			engine.stop();
		}
		~Car(){
			cout<<"Car Destroyed."<<endl;
		}
};

int main(int argc, char** argv){
	Car c;//car and engine created
	c.startCar();
	c.stopCar();
	return 0;//car and engine destroyed.
}