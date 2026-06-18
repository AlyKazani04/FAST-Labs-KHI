#include <iostream>
#include <stdlib.h>
using namespace std;

class Fruit{
	string name;
	public:
		Fruit(string n) : name(n) {}
		string getname(){ return name;}
};

class Blend{
	public:
		void blend(Fruit f){
			for(int i = 0; i < 5; i++){
				cout<<"Blending "<<f.getname()<<"..."<<endl;
				sleep(1);
			}
			cout<<"Blending complete."<<endl;
		}
};

class Grind{
	public:
		void grind(Fruit f){
			cout<<"Grinding "<<f.getname()<<"..."<<endl;
			sleep(5);
			cout<<"Grinding complete."<<endl;
		}
};

class JuiceMaker{
	Blend b;
	Grind g;
	Fruit f;
	public:
		JuiceMaker(Fruit fruit) : f(fruit) {}
		void setfruit(Fruit& fruit){
			f = fruit;
		}
		void BlendJuice(){
			b.blend(f);
		}
		void GrindJuice(){
			g.grind(f);
		}
};

int main(int argc, char** argv){
	Fruit Apple("Apple");
	Fruit Mango("Mango");
	JuiceMaker j(Apple);
	j.BlendJuice();
	j.setfruit(Mango);
	j.GrindJuice();
	return 0;
}
