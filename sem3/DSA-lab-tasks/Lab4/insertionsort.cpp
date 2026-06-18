#include <iostream>
using namespace std;

void display(int arr[], int n);

void insertionSort(int arr[], int n)
{   
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        display(arr, n);
        cout << endl;
    }
}

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int* arr = new int[5]{7,3,2,4,5};

    display(arr, 5);

    cout << endl;

    insertionSort(arr, 5);

    delete[] arr;

    return 0;
}