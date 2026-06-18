#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    // Loop until i and j cross each other
    while (i <= j) {
        // Move i to the right until we find an element greater than pivot
        while (i <= high && arr[i] <= pivot)
            i++;

        // Move j to the left until we find an element less than or equal to pivot
        while (j >= low && arr[j] > pivot)
            j--;

        if (i < j) {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; // pivot index
}


void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}