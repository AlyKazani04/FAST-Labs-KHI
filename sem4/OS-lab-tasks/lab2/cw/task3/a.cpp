#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    vector<int> vals;

    for(int i = 1; i < argc; i++)
    {
        vals.push_back(atoi(argv[i]));
    }

    sort(vals.begin(), vals.end());

    cout << "Sorted: " << endl;
    for(auto v : vals)
    {
        cout << v << ' ';
    }
    cout << endl;

    return 0;
}