#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int search)
{
    int start = 0;
    int end = size - 1;

    while(start <= end && search >= arr[start] && search <= arr[end])
    {
        if(start == end)
        {
            if(arr[start] == search) return start;

            return -1;
        }

        // estimate position
        int pos = start + ((search - arr[start]) * (end - start) / (arr[end] - arr[start]));

        // check if found
        if(arr[pos] == search) return pos;

        // if search greater than current position, ignore left side
        if(arr[pos] < search) start = pos + 1;
        // if search smaller than current, ignore right side
        else end = pos - 1;
    }

    return -1;
}

int main()
{

    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(int);

    cout << "Index: " << interpolationSearch(arr, 10, 70);

    return 0;
}