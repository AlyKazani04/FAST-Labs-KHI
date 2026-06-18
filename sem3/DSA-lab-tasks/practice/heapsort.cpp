#include <iostream>
using namespace std;

int parent(int i){ return (i-1)/2; }
int left(int i){ return 2*i + 1; };
int right(int i){ return 2*i + 2; };

void bubbledown(int arr[], int index, int n)
{
    int largest = index;
    int l = left(index);
    int r = right(index);
    
    if(l < n && arr[largest] < arr[l])
    {
        largest = l;
    }
    if(r < n && arr[largest] < arr[r])
    {
        largest = r;
    }

    if(index != largest)
    {
        swap(arr[index], arr[largest]);
        bubbledown(arr, largest, n);
    }
}

void heapify(int arr[], int n)
{
    int index = parent(n);
    for(int i = index; i >= 0; i--)
    {
        bubbledown(arr, i, n-1);
    }
}

void heapSort(int arr[], int n)
{
    heapify(arr, n);
    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        bubbledown(arr, 0, i);
    }
}

int main()
{
    int a[] = {5, 10, 7, 4, 35, 6, 23, 11};
    int n = 8;

    cout << "PreSort: ";
    for(int x : a)
    {
        cout << x << ' ';
    }
    cout << endl;

    heapSort(a, n);
    cout << "Sorted: ";
    for(int x : a)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}