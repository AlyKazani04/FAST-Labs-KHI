#include <bits/stdc++.h>
using namespace std;

class Book{
	string book_name;
	string isbn;
	string author_name;
	string publisher;
	public:
		Book(){
			cout<<"Default constructor called."<<endl;
		};
		Book(string bname, string Isbn, string aname, string publishername){
			book_name = bname;
			isbn = Isbn;
			author_name = aname;
			publisher = publishername;
			cout<<getBookInfo()<<endl;
		}
		string getbookname(){
			return book_name;
		}
		string getisbn(){
			return isbn;
		}
		string getauthorname(){
			return author_name;
		}
		string getpublisher(){
			return publisher;
		}
		string getBookInfo(){
			string bookinfo;
			bookinfo = "Book Name: " + getbookname() + "\nAuthor Name: " + getauthorname() + "\nISBN: " + getisbn() + "\nPublisher: " + getpublisher() + "\n";
			return bookinfo;
		}
};

int main(int argc, char** argv){
	
	//main input implementation
	/*Book books[5];
	for(int i = 0; i < 5; i++){
		books[i] = { Book(argv[i*4+1], argv[i*4+2], argv[i*4+3], argv[i*4+4] ) };  
	}*/
	
	//test default constructor
	//Book books_empty[5];
	
	Book books[5] = { 
		Book("Harry", "ab1234", "Author", "Publisher"), 
		Book("Book2", "ab2345", "Author1", "Publisher1")
		//3 empty spaces = 3 default constructors will be called.
	};
	
	return 0;
}
