#include <iostream>
#include <string>
using namespace std;

struct Item{
	string itemname;
	float cost;
	bool food;
};

class CoffeeShop{
	public:
		const string name;
		Item menu[10];
		int menusize;
		string orders[10];
		int ordersize;
		CoffeeShop(string n, Item m[], int msize) : name(n), menusize(msize){
			ordersize = 0;
			for(int i = 0; i < menusize; i++){
				menu[i] = m[i];
			}
		}
		string addOrder(string Iname){
			for(int i = 0; i < menusize; i++){
				if(menu[i].itemname == Iname){
					if(ordersize < 10){
						orders[ordersize] = Iname;
						ordersize++;
						return "Order Added.";
					}
				}
			}
			return "This item is currently unavailable.";
		}
		string fulfillOrder(){
			if(ordersize > 0){
				string fulfilled = orders[0];
				for(int i = 0; i < ordersize - 1; i++){
					orders[i] = orders[i+1];
				}
				ordersize--;
				return "The "+ fulfilled + " is ready.";
			}
			return "All orders have been fulfilled.";
		}
		void listOrders(){
			if(ordersize == 0){
				cout<<"[]"<<endl;
				return;
			}
			cout<<"Orders: "<<endl;
			for(int i = 0; i < ordersize; i++){
				cout<<orders[i]<<(( i < ordersize - 1) ? ", " : "");
			}
			cout<<endl;
		}
		float dueAmount(){
			float total = 0;
			for(int i = 0; i < ordersize; i++){
				for(int j = 0; j < menusize; j++){
					if(orders[i] == menu[j].itemname){
						total += menu[j].cost;
						break;
					}
				}
			}
			return total;
		}
		string cheapestItem(){
			if(menusize == 0){ return ""; }
			int cheapi = 0;
			for(int i = 1; i < menusize; i++){
				if(menu[i].cost < menu[cheapi].cost){
					cheapi = i;
				}
			}
			return menu[cheapi].itemname;
		}
		void drinksOnly(){
			cout<<"Drinks: ";
			for(int i = 0; i < menusize; i++){
				if(menu[i].food == false){
					cout<<menu[i].itemname<<" ";
				}
			}
			cout<<endl;	
		}
		void foodOnly(){
			cout<<"Food: ";
			for(int i = 0; i < menusize; i++){
				if(menu[i].food == true){
					cout<<menu[i].itemname<<" ";
				}
			}
			cout<<endl;	
		}
};

int main(int argc, char** argv){
	
	Item menu[] = {
		{ "Coffee", 2.5, false},
		{ "Tea" , 1.5, false},
		{ "Sandwich", 4.0, true},
		{ "Cake", 3.0, true}
	};
	
	CoffeeShop shop( "SattarBaksh Cafe", menu, 4);
	cout<<shop.addOrder("Burger")<<endl;
	cout<<shop.addOrder("Coffee")<<endl;
	cout<<shop.addOrder("Sandwich")<<endl;
	
	shop.listOrders();
	
	cout<<"Total Due: "<<shop.dueAmount()<<endl;
	
	cout<<shop.fulfillOrder()<<endl;
	
	shop.listOrders();
	
	cout<<"Cheapest Item: "<<shop.cheapestItem()<<endl;
	shop.foodOnly();
	shop.drinksOnly();
	
	return 0;
}
