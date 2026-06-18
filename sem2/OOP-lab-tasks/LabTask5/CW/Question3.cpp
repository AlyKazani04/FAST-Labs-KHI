#include <iostream>
#include <vector>
using namespace std;

class Catalog{
	int index;
	public:
		Catalog(): index(0){
		}
		~Catalog(){
		}
};

class Book{
	int ISBN;
	bool isLoaned;
	public:
		Book(){}
		Book(int is): ISBN(is), isLoaned(false){}
		int getisbn(){
			return ISBN;
		}
		bool getloanstatus(){
			return isLoaned;
		}
		void loanchange(){
			if(isLoaned == true){
				isLoaned = false;
				return;	
			}
			if(isLoaned == false){
				isLoaned = true;
			}
		}
		~Book(){
			cout<<this->getisbn()<<"\tBook Destroyed."<<endl;
		}
};

class Library{
	string name;
	Catalog cat;
	vector<Book*> books;
	public:
		Library(string n) : name(n){
		}
		void addBook(Book* b){
			books.push_back(b);
		}
		void removeBook(Book* b){
			vector<Book*> newbooks;
			for( Book* book : books){
				if(book->getisbn() == b->getisbn())	continue;
				newbooks.push_back(book);
			}
			books = newbooks;
		}
		void findBookinCatalog(int isbn){
			for(const auto& book : books){
				if(book->getisbn() == isbn){
					cout<<"Book Found"<<endl;
					return;
				}
			}
			cout<<"Book not Found"<<endl;
		}
		void listbooks(){
			for(const auto& book : books){
				cout<<"Book ISBN: "<<book->getisbn()<<endl;
				cout<<"Book Loan Status: "<<book->getloanstatus()<<endl;
			}
		}
		~Library(){
			for(const auto& book : books){
				book->~Book();
			}
			cout<<"Library destroyed"<<endl;
		}
};

int main(int argc, char** argv){
	Library lib("Fast Library");
	Book* book1 = new Book(21434);
	Book* book2 = new Book(21326);
	lib.addBook(book1);
	lib.addBook(book2);
	book1->loanchange();
	lib.listbooks();
	lib.findBookinCatalog(21326);
	
	return 0;
}