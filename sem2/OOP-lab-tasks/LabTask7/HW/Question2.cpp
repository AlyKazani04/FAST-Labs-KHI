#include <iostream>
using namespace std;

class Shape{ // Square
    private:
        float side;
    public:
        Shape(float s): side(s) {}
        float getArea() { return side * side; }
        float operator+(Shape& other){
            return getArea() + other.getArea();
        }
};

int main(){
    Shape shape1(15);
    Shape shape2(20);

    cout<<"Combined Area: "<<shape1 + shape2<<"m^2"<<endl;

    return 0;
}