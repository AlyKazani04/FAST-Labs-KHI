#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start;
    int j = end - 1;

    while(i <= j)
    {
        while(i <= end && arr[i] <= pivot) i++;
        while(j >= start && arr[j] > pivot) j--;

        if(i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    int temp = arr[end];
    arr[end] = arr[i];
    arr[i] = temp;

    return i;
}

void quicksort(int arr[], int start, int end)
{
    if(start <= end)
    {
        int pi = partition(arr, start, end);

        quicksort(arr, start, pi - 1);
        quicksort(arr, pi + 1, end);
    }
}

int main()
{
    int arr[6] = {5, 7, 3, 8, 10, 1};

    quicksort(arr, 0, 5);

    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' ';
    }    

    return 0;
}