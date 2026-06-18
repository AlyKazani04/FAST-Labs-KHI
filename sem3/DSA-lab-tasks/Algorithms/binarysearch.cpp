#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int* arr, int size, int search)
{
    int startIndex = 0;
    int lastIndex = size - 1;
    
    while(startIndex <= lastIndex)  // CHECK
    {   
        int midIndex = round(startIndex + lastIndex) / 2;

        if(arr[midIndex] == search)
        {
            cout << "Found." << endl;
            return arr[midIndex];
        }
        else
        {
            if(arr[midIndex] < search)
            {
                startIndex = midIndex + 1;
            }
            else
            {
                lastIndex = midIndex - 1;
            }
        }
    }

    cout << "Value not found." << endl;
    return -1;
}

int main()
{
    int* sortedArr = new int[10]{1,2,3,4,5,6,7,8,9,10};

    cout << binarySearch(sortedArr, 10, 2);

    delete[] sortedArr;

    return 0;
}