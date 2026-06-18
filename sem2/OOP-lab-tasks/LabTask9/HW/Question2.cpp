#include <iostream>
#include <string>
using namespace std;

class Car{
    protected:
        string model;
        float price;
    public:
        Car(string m, float f) : model(m), price(f) {}
        float getPrice(){
            return price;
        }
        string getModel(){
            return model;
        }
        void setModel(string m){
            model = m;
        }
        virtual void setPrice(float f) = 0;
        virtual void display(){
            cout<<"Car Display:\n";
            cout << "Model: " << model << endl;
            cout << "Price: " << price << endl;
        };
};

class Color : public Car{
    private:
        string color;
    public:
        Color(string m, float f, string c) : Car(m, f), color(c) {}
        void setPrice(float f) override {
            price = f;
        }
        void display() override {
            cout<<"Color Display:\n";
            cout << "Model: " << model << endl;
            cout << "Price: " << price << endl;
            cout << "Color: " << color << endl;
        }
};

class Company : public Car{
    private:
        string company_name;
    public:
        Company(string m, float f, string c) : Car(m, f), company_name(c) {}
        void setPrice(float f) override {
            price = f;
        }
        void display() override {
            cout<<"Company Display:\n";
            cout << "Model: " << model << endl;
            cout << "Price: " << price << endl;
            cout << "Company: " << company_name << endl;
        }
};

int main(){
    Car* cars[2] ={
        new Color("Toyota", 20000.0, "Red"),
        new Company("Honda", 25000.0, "Honda Company")
    };
    float setting_price = 42000.f;
    for(auto car : cars){
        car->setPrice(setting_price++);
        car->display();
        delete car;
    }
    return 0;
}