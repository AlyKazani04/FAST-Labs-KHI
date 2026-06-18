#include <iostream>
using namespace std;

int factorial(int n) // direct, non-tail recursion
{
    if(n == 1)
    {
        cout << n << endl;
        return 1;
    }
    cout << n << " x "; 
    return n * factorial(n-1); // any other computation aside from direct return = non-tail recursion
}

int main()
{

    cout << factorial(8);

    return 0;
}