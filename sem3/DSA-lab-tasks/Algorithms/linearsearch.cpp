#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int search)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == search)
        {
            cout << "Found." << endl;
            return i;
        }

    }
    cout << "Not found." << endl;
    return -1;
}