#include <iostream>
#include <limits>
using namespace std;

struct review
{
    int stars;
    string text;

    review() = default;
    review(int s, string t) : stars(s), text(t) {}
};


void merge(review* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // size of left subarray
    int n2 = right - mid;    // size of right subarray
    
    // Create temporary arrays
    review* L = new review[n1];
    review* R = new review[n2];
    
    // Copy data to temp arrays L[] and R[]
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i].stars < R[j].stars)
        {
            arr[k] = L[i];
            i++;
        }
        else if(L[i].stars == R[j].stars)
        {
            if(L[i].text.compare(R[j].text) <= 0)
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Free allocated memory
    delete[] L;
    delete[] R;
}

void mergeSort(review* arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printReviews(review* reviews, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "Stars: " << reviews[i].stars << endl;
        cout << "Review: " << reviews[i].text << endl << endl;
    }
}

int main()
{
    int s;
    string t;
    review* reviews = new review[3];
    for(int i = 0; i < 3; i++)
    {
        cout << "Leave a review: " << endl;
        cout << "Stars(1-5): ";
        cin >> s;

        if(cin.fail() || s > 5 || s < 1) // input validation
        {
            do
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Try again.\n Stars: ";
                cin >> s;
            }while(cin.fail());
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Comment: ";
        getline(cin, t);

        reviews[i].stars = s;
        reviews[i].text = t;

    }

    mergeSort(reviews, 0, 2);

    cout << "\nReviews:\n";

    printReviews(reviews, 3);

    delete[] reviews;

    return 0;
}