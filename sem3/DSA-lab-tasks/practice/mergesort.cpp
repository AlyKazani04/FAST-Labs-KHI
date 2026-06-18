#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    
    int l[n1], r[n2];

    for(int i = 0; i < n1; i++)
    {
        l[i] = arr[start + i];
    }

    for(int i = 0; i < n2; i++)
    {
        r[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while(i < n1 && j < n2)
    {
        if(l[i] <= r[j])
        {
            arr[k++] = l[i++];
        }
        else
        {
            arr[k++] = r[j++];
        }
    }

    while(i < n1)
    {
        arr[k++] = l[i++];
    }

    while(j < n2)
    {
        arr[k++] = r[j++];
    }
    
}

void mergeSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[6] = {5, 7, 3, 8, 10, 1};

    mergeSort(arr, 0, 5);

    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' '; 
    }

    return 0;
}