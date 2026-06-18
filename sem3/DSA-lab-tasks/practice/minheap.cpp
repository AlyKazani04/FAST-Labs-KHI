#include <iostream>
using namespace std;

class minHeap
{
    private:
        int* arr;
        int capacity;
        int size;

        int parent(int i){ return (i - 1) / 2; }
        int left(int i){ return 2 * i + 1; }
        int right(int i){ return 2 * i + 2; }

        void bubbleup(int i)
        {
            while(i != 0 && arr[i] < arr[parent(i)])
            {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }

        void bubbledown(int i)
        {
            int smallest = i;
            int l = left(i);
            int r = right(i);

            if(arr[l] < arr[i])
            {
                smallest = l;
            }
            if(arr[r] < arr[i]);
            {
                smallest = r;
            }

            if(smallest != i)
            {
                swap(arr[smallest], arr[i]);
                bubbledown(smallest);
            }
        }

    public:
        minHeap(int cap) : capacity(cap), size(0)
        {
            arr = new int[capacity];
        }

        ~minHeap()
        {
            delete[] arr;
        }

        void insert(int i)
        {
            if(size == capacity)
            {
                cout << "Heap Full!" << endl;
                return;
            }
            arr[size] = i;
            bubbleup(size);
            size++;
        }

        void deleteMin()
        {
            if(size == 0)
            {
                cout << "Heap is empty!" << endl;
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