#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159

class Circle{
	int radius;
	public:
	Circle(int val = 1){
		radius = val;
	}
	float getArea(){
		return PI * radius * radius;
	}
	float getPerimeter(){
		return 2*PI*radius;
	}
};
int main(){
	Circle c(3);
	cout<<fixed<<setprecision(2)<<c.getArea()<<endl;
	cout<<fixed<<setprecision(2)<<c.getPerimeter();
}