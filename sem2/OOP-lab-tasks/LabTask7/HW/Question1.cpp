#include <iostream>
using namespace std;

class Overload{
    private:
        float x;
    public:
        Overload(float x) : x(x){}    
        float operator--(){
            return x*4;
        }
        
        float operator--(int){
            return x/4;
    }
};

int main(){
    Overload num(16);

    cout<<num--<<endl; // Outputs: 4
    cout<<--num<<endl; // Outputs: 64
    
    return 0;
}