#include <iostream>
using namespace std;

class Shape{
    public:
        virtual float getArea() = 0;
};

class Rectangle : public Shape{
    private:
        float length;
        float width;
    public:
        Rectangle(float l = 1, float w = 2) : length(l), width(w) {}

        float getArea() override{
            return length * width;
        }
};

class Triangle : public Shape{
    private:
        float base;
        float height;
    public:
        Triangle(float b = 1, float h = 1) : base(b), height(h) {}

        float getArea() override{
            return 0.5 * base * height;
        }
};

int main(){

    Rectangle r(3, 5.6f);
    Triangle t(2.3f, 4.5f);

    cout<<"Rectangle Area: "<<r.getArea()<<endl;
    cout<<"Triangle Area: "<<t.getArea()<<endl;
    return 0;
}