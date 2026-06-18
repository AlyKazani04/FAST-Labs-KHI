#include <iostream>
using namespace std;

void display(int arr[], int n);

void selectionSort(int* arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {   
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);

        display(arr, 5);
    }
}   

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int* arr = new int[5]{7,2,3,4,5};

    display(arr, 5);

    selectionSort(arr, 5);

    delete[] arr;

    return 0;
}