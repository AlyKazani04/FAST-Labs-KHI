#include <bits/stdc++.h>
using namespace std;

class Vehicles{
	protected:
		float price;
	public:
		Vehicles(float p) : price(p) {}
		virtual void display(){
	    	cout<<"Price: $"<<price<<endl;
		}
};

class Car : public Vehicles{
	protected:
		int seating_capacity;
		int num_doors;
		string fuel_type;
	public:
		Car(float p, int seat, int doors, string f) : Vehicles(p), seating_capacity(seat), num_doors(doors), fuel_type(f) {}
		virtual void display(){
	    	cout<<"Price: $"<<price<<endl;
	    	cout<<"Seating Capacity: "<<seating_capacity<<endl;
        	cout<<"Number of Doors: "<<num_doors<<endl;
        	cout<<"Fuel Type: "<<fuel_type<<endl;
		}
};

class Motorcycle : public Vehicles{
	protected:
		int num_cylinders;
		int num_gears;
		int num_wheels;
	public:
		Motorcycle(int p, int cyl, int ge, int whe): Vehicles(p), num_cylinders(cyl), num_gears(ge), num_wheels(whe) {}
		void display() override{
	    	cout<<"Price: $"<<price<<endl;
	    	cout<<"Number of Cylinders: "<<num_cylinders<<endl;
        	cout<<"Number of Gears: "<<num_gears<<endl;
        	cout<<"Number of Wheels: "<<num_wheels<<endl;
		}
};

class Audi : public Car{
	private:
		string model_type;
	public:
		Audi(string model, float p, int seat, int doors, string f) : Car(p, seat,doors, f), model_type(model) {}
		void display() override{
	    	cout<<"Price: $"<<fixed<<setprecision(1)<<price<<endl;
	    	cout<<"Seating Capacity: "<<seating_capacity<<endl;
        	cout<<"Number of Doors: "<<num_doors<<endl;
        	cout<<"Fuel Type: "<<fuel_type<<endl;
        	cout<<"Model Type: "<<model_type<<endl;
		}
};

class Yamaha : public Motorcycle{
	private:
		string make_type;
	public:
		Yamaha(string make, float p, int cyl, int ge, int whe) : Motorcycle(p, cyl, ge, whe), make_type(make) {}
		void display() override{
	    	cout<<"Price: $"<<fixed<<setprecision(1)<<price<<endl;
	    	cout<<"Number of Cylinders: "<<num_cylinders<<endl;
        	cout<<"Number of Gears: "<<num_gears<<endl;
        	cout<<"Number of Wheels: "<<num_wheels<<endl;
        	cout<<"Make Type: "<<make_type<<endl;
		}
};

int main(int argc, char** argv){
	Audi car("Audi Supreme", 500000.0, 5, 4, "Petrol");
    Yamaha bike("Yamaha R1", 15000.0, 2, 6, 2);

    cout<<"Audi: "<<endl;
    car.display();
	cout<<endl;
    cout<<"Yamaha: "<<endl;
    bike.display();
	return 0;
}
