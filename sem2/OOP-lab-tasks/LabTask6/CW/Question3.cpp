#include<iostream>
#include<string>
using namespace std;

class Employee{
	protected:
	    int id;
	    string name;
	public:
	    Employee(int i,string n):id(i),name(n){}
	    virtual ~Employee(){}
	    virtual void DisplayInfo()
	    {
	        cout<<"ID:"<<id<<", Name:"<<name<<'\n';
	    }
};

class IOrderTaker{
	public:
	    virtual void TakeOrder(string ord)=0;
	    virtual ~IOrderTaker(){}
};

class IOrderPreparer{
	public:
	    virtual void PrepareOrder(string ord)=0;
	    virtual ~IOrderPreparer(){}
};

class IBiller{
	public:
	    virtual void GenerateBill(float amt)=0;
	    virtual ~IBiller(){}
};

class Waiter:public Employee,public IOrderTaker{
	public:
	    Waiter(int i,string n):Employee(i,n){}
	    void TakeOrder(string ord) override
	    {
	        cout<<name<<" took order:"<<ord<<'\n';
	    }
};

class Chef:public Employee,public IOrderPreparer{
	public:
	    Chef(int i,string n):Employee(i,n){}
	    void PrepareOrder(string ord) override{
	        cout<<name<<" is preparing:"<<ord<<'\n';
	    }
};

class Cashier:public Employee,public IBiller{
	public:
	    Cashier(int i,string n):Employee(i,n){}
	    void GenerateBill(float amt) override{
	        cout<<name<<" generated a bill of:$"<<amt<<'\n';
	    }
};

class Manager:public Employee,public IOrderTaker,public IBiller{
	public:
	    Manager(int i,string n):Employee(i,n){}
	    void TakeOrder(string ord) override{
	        cout<<name<<" took an order as a manager:"<<ord<<'\n';
	    }
	    void GenerateBill(float amt) override{
	        cout<<name<<" generated a bill as a manager:$"<<amt<<'\n';
	    }
};

class Menu{
	protected:
	    string menuName;
	public:
	    Menu(string mn):menuName(mn){}
	    virtual ~Menu(){}
	    virtual float CalculateTotal(float baseP);
};

class FoodMenu:public Menu{
	public:
	    FoodMenu():Menu("Food Menu"){}
	    float CalculateTotal(float baseP) override{
	        return baseP;
	    }
};

class BeverageMenu:public Menu{
	public:
	    BeverageMenu():Menu("Beverage Menu"){}
	    float CalculateTotal(float baseP) override{
	        return baseP*1.10f; 
	    }
};

int main(){
    Waiter waiter1(1,"John");
    Chef chef1(2,"Alice");
    Cashier cashier1(3,"Bob");
    Manager manager1(4,"Sarah");
    
    waiter1.TakeOrder("Pasta");
    chef1.PrepareOrder("Pasta");
    cashier1.GenerateBill(12.99f);
    manager1.TakeOrder("Cola");
    manager1.GenerateBill(25.00f);
    
    FoodMenu foodMenu;
    BeverageMenu beverageMenu;
    
    cout<<"Food cost: "<<foodMenu.CalculateTotal(10.0f)<<'\n';
    cout<<"Beverage cost: "<<beverageMenu.CalculateTotal(5.0f)<<'\n';
    
    return 0;
}
