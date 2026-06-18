#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j;

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            
            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[6] = {5, 7, 3, 8, 10, 1};

    shellSort(arr, 6);

    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' ';
    }    

    return 0;
}