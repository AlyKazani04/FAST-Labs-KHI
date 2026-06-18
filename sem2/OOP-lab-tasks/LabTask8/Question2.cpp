#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define PI 3.14159

class Shape{
    protected:
        float x;
        float y;
        string color;
    public:
        Shape(float x, float y, string col) : 
            x(x), y(y), color(col) {}
        virtual void draw(){}
        virtual float calculateArea(){}
        virtual float calculatePerimeter(){}
    ~Shape(){}
};

class Circle : public Shape{
    private:
        float radius;
    public:
        Circle(float x, float y, string col, float r) :
            Shape(x, y, col), radius(r) {}
        void draw() override{
            cout<<"Drawing a Circle at ("<<x<<", "<<y<<") with radius "<<radius<<endl;
        }
        float calculateArea() override{
            return PI * radius * radius;
        }
        float calculatePerimeter() override{
            return 2 * PI * radius;
        }
};

class Rectangle : public Shape{
    private:
        float width;
        float height;
    public:
        Rectangle(float x, float y, string col, float w, float h):
            Shape(x, y, col), width(w), height(h) {}
        void draw() override{
            cout<<"Drawing a Rectangle at ("<<x<<", "<<y<<") with width "<<width<<" and height "<<height<<endl;
        }
        float calculateArea() override{
            return width * height;
        }
        float calculatePerimeter(){
            return 2 * (width + height);
        }
};

class Triangle : public Shape{
    private:
        float a;
        float b;
        float c;
    public:
        Triangle(float x, float y, string col, float a, float b, float c):
            Shape(x, y, col), a(a), b(b), c(c) {}
        void draw() override{
            cout<<"Drawing a Triangle at ("<<x<<", "<<y<<") with sides "<<a<<", "<<b<<", "<<c<<endl;
        }
        float calculateArea() override{
            float s = (a + b + c)/2;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }
        float calculatePerimeter() override{
            return a + b + c;
        }
};

class Polygon : public Shape {
    private:
        vector<float> vertices_x;
        vector<float> vertices_y;
    public:
        Polygon(vector<float> xVertices, vector<float> yVertices, std::string color)
            : Shape(0, 0, color), vertices_x(xVertices), vertices_y(yVertices) {}
        void draw() override {
            cout<<"Drawing Polygon with sides "<<vertices_x.size()<<endl;
        }
        float calculateArea() override {
            float area = 0.0;
            int n = vertices_x.size();
            for (int i = 0; i < n; i++) {
                area += (vertices_x[i] * vertices_y[(i + 1) % n]) - (vertices_y[i] * vertices_x[(i + 1) % n]);
            }
            return abs(area) / 2.0;
        }
        float calculatePerimeter() override {
            float perimeter = 0.0; 
            int n = vertices_x.size();
            for(int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                perimeter += hypot(vertices_x[j] - vertices_x[i], vertices_y[j] - vertices_y[i]); 
            }
            return perimeter;
        }
};

int main(){

    Circle c(5, 5, "red", 1.5);
    Rectangle r(0, 0, "blue", 2, 4);
    Triangle t(0, 0, "green", 3, 4, 5);
    Polygon p({0, 4, 4, 0}, {0, 0, 3, 3}, "yellow");

    c.draw();
    cout<<"Circle Area: "<<c.calculateArea()<<endl;
    cout<<"Circle Perimeter: "<<c.calculatePerimeter()<<"\n"<<endl;

    r.draw();
    cout<<"Rectangle Area: "<<r.calculateArea()<<endl;
    cout<<"Rectangle Perimeter: "<<r.calculatePerimeter()<<"\n"<<endl;

    t.draw();
    cout<<"Triangle Area: "<<t.calculateArea()<<endl;
    cout<<"Triangle Perimeter: "<<t.calculatePerimeter()<<"\n"<<endl;

    p.draw();
    cout<<"Polygon Area: "<<p.calculateArea()<<endl;
    cout<<"Polygon Perimeter: "<<p.calculatePerimeter()<<endl;
    
    return 0;
}