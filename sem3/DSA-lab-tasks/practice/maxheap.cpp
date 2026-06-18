#include <iostream>
using namespace std;

class MaxHeap
{
    private:
        int* arr;
        int size;
        int capacity;

        int parent(int i){ return (i - 1) / 2; }
        int left(int i){ return 2 * i + 1; }
        int right(int i){ return 2 * i + 2; }

        void bubbleup(int i)
        {
            while(i != 0 && arr[i] > arr[parent(i)])
            {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }

        void bubbledown(int i)
        {
            int largest = i;
            int l = left(i);
            int r = right(i);

            if(arr[l] > arr[i])
            {
                largest = l;
            }
            if(arr[r] > arr[i])
            {
                largest = r;
            }

            if(i != largest)
            {
                swap(arr[largest], arr[i]);
                bubbledown(largest);
            }
        }
    public:
        MaxHeap(int cap) : capacity(cap), size(0)
        {
            arr = new int[capacity];
        }
        ~MaxHeap()
        {
            delete[] arr;
        }

        void insert(int i)
        {
            if(size == capacity)
            {
                cout << "Heap full!" << endl;
                return;
            }
            arr[size];
            bubbleup(size);
            size++;
        }

        void removeMax()
        {
            if(size == 0)
            {
                cout << "Heap is Empty!" << endl;
                return; 
            }
            arr[0] = arr[size - 1];
            size--;
            bubbledown(0);
        }
};

int main()
{

    return 0;
}