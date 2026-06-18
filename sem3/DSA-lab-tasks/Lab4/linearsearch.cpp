#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int search)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == search)
        {
            cout << "Found. \nIndex: " << i << endl;
            return;
        }

    }
    cout << "Not found." << endl;
}

int main()
{
    int* arr = new int[5]{7,3,2,4,5};

    linearSearch(arr, 5, 2);

    delete[] arr;

}