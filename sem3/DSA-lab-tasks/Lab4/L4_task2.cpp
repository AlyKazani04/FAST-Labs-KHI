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

void selectionSort(int* arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {   
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] <= arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);

        display(arr, n);
    }
} 

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

int selectionSortthenInterpolation(int arr[], int size, int target)
{   
    selectionSort(arr, size);

    int index = interpolationSearch(arr, size, target);
    return index;
}

int main()
{
    int* arr = new int[6]{9,8,5,4,5,6};
    int* anotherArr = new int[7]{2,8,10,6,4,22,12};

    display(arr, 6);
    
    int index = selectionSortthenInterpolation(arr, 6, 9);

    cout << "Value: 9 Index: " << index << endl;

    index = selectionSortthenInterpolation(anotherArr, 7, 11);

    cout << "Value: 11 Index: " << index << endl;

    delete[] arr;
    delete[] anotherArr;

    return 0;
}