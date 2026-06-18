#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class Date{
	int month;
	int day;
	int year;
	public:
		Date(int a, int b, int c){
			day = a;
			month = b;
			year = c;
		}
		void DisplayDate(){
			cout<<"Date: "<<day<<"/"<<month<<"/"<<year<<endl;
		}
};

int main(int argc, char** argv){
	Date date( atoi(argv[1]), atoi(argv[2]), atoi(argv[3]) );
	date.DisplayDate();
	return 0;
}
