#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

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

int binarySearch(int* arr, int size, int search)
{
    int startIndex = 0;
    int lastIndex = size - 1;
    
    while(startIndex <= lastIndex)
    {   
        int midIndex = (startIndex + lastIndex) / 2;

        if(arr[midIndex] == search)
        {
            cout << "Found." << endl;
            return midIndex;
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

int insertionSortthenSearch(int arr[], int size, int target)
{
    insertionSort(arr, size);
    int index = binarySearch(arr, size, target);
    return index;
}

int main()
{
    int* arr = new int[5]{7,3,2,4,5};
    int* anotherArr = new int[7]{2,8,10,6,4,22,12};

    display(arr, 5);

    cout << endl;

    int index = insertionSortthenSearch(arr, 5, 7);
    
    cout << "Found at Index: " << index << endl;

    index = insertionSortthenSearch(anotherArr, 7, 11);

    cout << "Index: " << index << endl;

    delete[] arr;
    delete[] anotherArr;
    
    return 0;
}