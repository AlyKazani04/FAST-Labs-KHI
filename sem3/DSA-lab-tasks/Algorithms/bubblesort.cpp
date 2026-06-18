#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    bool swap = false;
    for(int i = size - 1; i > 0; i--)
    {
        swap = false;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }

        if(swap == false)
        {
            break;
        }
    }
}