#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Base{
    protected:
        T var_A;
        T var_B;
        T multiplyBase() const{
            T result = var_A * var_B;
            return result;
        }
    public: 
        Base(T A, T B) : var_A(A), var_B(B) {}
        
};

template <class T>
class Derived: public Base<T>{
    private:
        T var_C;
        T var_D;
        T multiplyDerived() const{
            T result = var_C * var_D;
            return result;
        }
    public:
        Derived(T a, T b, T c, T d) : Base<T>(a,b), var_C(c), var_D(d) {}
        void print(){
            cout<<"Base Multiplication: "<<this->multiplyBase()<<endl;

            cout<<"Derived Multiplication: "<<multiplyDerived()<<endl;
        }
};

int main(){

    Derived <float>d(12.f, 11.f, 10, 111.1);

    d.print();

    return 0;
}