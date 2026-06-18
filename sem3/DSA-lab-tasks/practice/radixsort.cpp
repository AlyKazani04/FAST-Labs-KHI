#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

int getMax(int arr[], int size)
{
    int max = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void clearBucket(Node*& bucket)
{
    Node* temp;
    while(bucket != nullptr)
    {
        temp = bucket;
        bucket = bucket->next;
        delete temp;
    }
}

void insertBucket(int val, Node*& bucket)
{
    Node* newNode = new Node(val);
    if(bucket == nullptr)
    {
        bucket = newNode; 
        return;
    }

    Node* temp = bucket;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void radixSort(int arr[], int size)
{   
    Node* buckets[10] = {nullptr};
    int exp = 1;
    int max = getMax(arr, size);

    while(max / exp > 0)
    {
        for(int i = 0; i < 10; i++)
        {
            buckets[i] = nullptr;
        }

        for(int i = 0; i < size; i++)
        {
            int digit = (arr[i] / exp) % 10;

            insertBucket(arr[i], buckets[digit]);
        }

        int i = 0;
        for(int j = 0; j < 10; j++)
        {
            Node* temp = buckets[j];
            while(temp != nullptr)
            {
                arr[i++] = temp->val;
                temp = temp->next;
            }
            clearBucket(buckets[j]);
        }

        exp *= 10;
    }
    
}

int main()
{
    int arr[6] = {5, 7, 3, 8, 10, 1};

    radixSort(arr, 6);

    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}