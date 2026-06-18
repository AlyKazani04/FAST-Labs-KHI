#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct User{
	string user_id, first_name, last_name, address, email;
};

struct Product{
	string product_id, product_name, description;
	int price;
};

struct Order{
	string order_id, user_id, product_id;
	int total_paid;
};

vector<Product> getProducts(const string& filename){
	vector<Product> products;
	ifstream file(filename);
	string line;

	while (getline(file, line)) {
		stringstream inp(line);
		Product p;
		string price_str;
		getline(inp, p.product_id, ',');
		getline(inp, p.product_name, ',');
		getline(inp, p.description, ',');
		getline(inp, price_str, ',');
		p.price = stoi(price_str);
		products.push_back(p);
		}

	return products;
}

vector<User> getUsers(const string& filename){
    vector<User> users;
	ifstream file(filename);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		User u;
		getline(ss, u.user_id, ',');
		getline(ss, u.first_name, ',');
		getline(ss, u.last_name, ',');
		getline(ss, u.address, ',');
		getline(ss, u.email, ',');
		users.push_back(u);
		}
	return users;
}

vector<Order> getOrders(const string& filename){
    vector<Order> orders;
	ifstream file(filename);
	string line;

	while (getline(file, line)) {
		stringstream inp(line);
		Order o;
		string total_paid_str;
		getline(inp, o.order_id, ',');
		getline(inp, o.user_id, ',');
		getline(inp, o.product_id, ',');
		getline(inp, total_paid_str, ',');
		o.total_paid = stoi(total_paid_str);
		orders.push_back(o);
	}
	return orders;
}

int main(){
    vector<User> users = getUsers("Users.txt");
    vector<Product> products = getProducts("Products.txt");
    vector<Order> orders = getOrders("Orders.txt");

    string linus_id = "";
    for(const auto& user : users){
        if(user.first_name == "Linus"){
            linus_id = user.user_id;
            break;
        }
    }

    if(linus_id.empty()){
        cout<<"Linus not Found.\n";
        return 1;
    }

    vector<string> linus_products;
    for(const auto& order : orders){
        if(order.order_id == linus_id){
            linus_products.push_back(order.product_id);
        }
    }

    for(const auto& prod : linus_products){
        cout<<prod<<endl;
    }
    
    return 0;
}