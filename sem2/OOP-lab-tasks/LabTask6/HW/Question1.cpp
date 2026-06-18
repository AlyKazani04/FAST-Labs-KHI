#include <bits/stdc++.h>
#include <string>
using namespace std;

class Books{
	protected:
    	string genre;
	public:
		Books(string g) : genre(g) {}
		void display(){
			cout<<"Genre: "<<genre<<endl;
	    }
};

class Action : public Books{
	private:
		string title;
		string author;
	
	public:		
		Action(string t, string a) : Books("Action"), title(t), author(a) {}
		virtual void display(){
			cout<<"Title: "<<title<<endl;
			cout<<"Author: "<<author<<endl;
			cout<<"Genre: "<<genre<<endl;
		}
};

class Cultivation : public Books {
	private:
		string title;
		string author;
	public:
		Cultivation(string t, string a) : Books("Cultivation"), title(t), author(a) {}
		virtual void display(){
			cout<<"Title: "<<title<<endl;
			cout<<"Author: "<<author<<endl;
			cout<<"Genre: "<<genre<<endl;
		}
};


int main() {
    Action book1("Lord Of The Mysteries", "Cuttlefish That Loves Diving");
    Cultivation book2("Reverend Insanity", "Gu Zhen Re");

    cout<<"Library: "<<endl<<endl;
    book1.display();
    cout<<endl;
    book2.display();
    cout<<endl;

    return 0;
}