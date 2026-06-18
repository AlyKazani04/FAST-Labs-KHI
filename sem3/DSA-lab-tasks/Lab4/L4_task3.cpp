#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

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
        
        display(arr, size);
    }
}

int bubbleSortthenLinear(int arr[], int size, int target)
{
    bubbleSort(arr, size);

    int index = linearSearch(arr, size, target);

    return index;
}

int main()
{
    int* arr = new int[6]{9,8,5,4,5,6};
    int* anotherArr = new int[7]{2,8,10,6,4,22,12};

    display(arr, 6);
    
    int index = bubbleSortthenLinear(arr, 6, 9);

    cout << "Value: 9 Index: " << index << endl;

    display(anotherArr, 7);

    index = bubbleSortthenLinear(anotherArr, 7, 11);

    cout << "Value: 11 Index: " << index << endl;

    delete[] arr;
    delete[] anotherArr;

    return 0;
}