#include <bits/stdc++.h>
#include <string>
using namespace std;

struct MenuItem{
	string name;
	string type;
	double price;
};

class CoffeeShop{
private:
	string name;
	MenuItem menu[10];
	string orders[10];
	int menuSize;
	int orderSize;

public:
	CoffeeShop(string shopName, MenuItem m[], int mSize){
		name = shopName;
		menuSize = mSize;
		orderSize = 0;
		for(int i = 0; i < mSize; i++){
			menu[i] = m[i];
		}
	}

	string addOrder(string itemName){
		for(int i = 0; i < menuSize; i++){
			if(menu[i].name == itemName){
				if(orderSize < 10){
					orders[orderSize++] = itemName;
					return "Order added";
				}
			}
		}
		return "This item is currently unavailable";
	}

	string fulfillOrder(){
		if(orderSize > 0){
			string fulfilled = orders[0];
			for(int i = 0; i < orderSize - 1; i++){
				orders[i] = orders[i + 1];
			}
			orderSize--;
			return "The " + fulfilled + " is ready";
		}
		return "All orders have been fulfilled";
	}

	void listOrders(){
		if(orderSize == 0){
			cout<<"[]"<<endl;
			return;
		}
		cout<<"Orders: ";
		for(int i = 0; i < orderSize; i++){
			cout<<orders[i]<<(i < orderSize - 1 ? ", " : "");
		}
		cout<<endl;
	}

	double dueAmount(){
		double total = 0.0;
		for(int i = 0; i < orderSize; i++){
			for(int j = 0; j < menuSize; j++){
				if(orders[i] == menu[j].name){
					total += menu[j].price;
					break;
				}
			}
		}
		return total;
	}

	string cheapestItem(){
		if(menuSize == 0) return "";
		int cheapestIndex = 0;
		for(int i = 1; i < menuSize; i++){
			if(menu[i].price < menu[cheapestIndex].price){
				cheapestIndex = i;
			}
		}
		return menu[cheapestIndex].name;
	}

	void drinksOnly(){
		cout << "Drinks: ";
		for(int i = 0; i < menuSize; i++){
			if(menu[i].type == "drink"){
				cout<<menu[i].name<<" ";
			}
		}
		cout<<endl;
	}

	void foodOnly(){
		cout<<"Food: ";
		for(int i = 0; i < menuSize; i++){
			if(menu[i].type == "food"){
				cout<<menu[i].name<<" ";
			}
		}
		cout<<endl;
	}
};

int main(){
	MenuItem menu[] = {
		{"Coffee", "drink", 2.5},
		{"Tea", "drink", 1.5},
		{"Sandwich", "food", 4.0},
		{"Cake", "food", 3.0}
	};
	
	CoffeeShop shop("Cafe Delight", menu, 4);
	
	cout<<shop.addOrder("Coffee")<<endl;
	cout<<shop.addOrder("Cake")<<endl;
	cout<<shop.addOrder("Pizza")<<endl;
	
	shop.listOrders();
	
	cout<<"Total Due: "<<shop.dueAmount()<<endl;
	
	cout<<shop.fulfillOrder()<<endl;
	shop.listOrders();
	
	cout<<"Cheapest Item: "<<shop.cheapestItem()<<endl;
	
	shop.drinksOnly();
	shop.foodOnly();
	
	return 0;
}
