#include <iostream>
using namespace std;

int M(int n)
{
    if(n > 100)
    {
        return n - 10;
    }
    else 
    {
        return M(M(n + 11));
    }
}

int main()
{
    int n = 97;

    cout << M(n);
    return 0;
}
