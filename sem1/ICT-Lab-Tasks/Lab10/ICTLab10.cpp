#include <iostream>
#include <string>
using namespace std;

class LibraryBook{
	private:
		int availableCopies;
	public:
		string title;
		string author;
		long ISBN;
		LibraryBook():availableCopies(0){}
		void setCopies(int copies){
			availableCopies += copies;
		}
		int getCopies(){
			return availableCopies;
		}
		void displayDetails(){
				cout<<"Book Title : "<<title<<endl;
				cout<<"Book Author : "<<author<<endl;
				cout<<"Book ISBN : "<<ISBN<<endl;
				cout<<"Books available : "<<getCopies()<<endl;
		}
};

int main(){
	int copies;
	LibraryBook book;
	
	cout<<"Enter Book Title : "<<endl;
	getline(cin, book.title);
	cout<<"Enter Book Author : "<<endl;
	getline(cin, book.author);
	cout<<"Enter Book ISBN : "<<endl;
	cin>>book.ISBN;
	cout<<"Enter Available Copies: "<<endl;
	cin>>copies;
	cout<<"\n";
	
	book.setCopies(copies);
	cout<<"Book Details:\n\nf";
	book.displayDetails();
	
	return 0;
}
