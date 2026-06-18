#include <iostream>
using namespace std;

class CircularQueue
{
    private:
        int* arr;
        int front;
        int back;
        const int capacity;
    public:
        CircularQueue(int cap) : capacity(cap), front(-1), back(-1)
        {
            arr = new int[cap];
        }

        bool isFull()
        {
            return (front + 1) % capacity == back;
        }

        bool isEmpty()
        {
            return back == -1 && front == -1;
        }

        void enqueue(int val)
        {
            if(isFull())
            {
                cout << "Queue is full!" << endl;
                return;
            }
            if(isEmpty())
            {
                back = (back + 1) % capacity;
            }
            front = (front + 1) % capacity;
            arr[front] = val;
        }

        int dequeue()
        {
            if(isEmpty())
            {
                cout << "Queue is empty!" << endl;
                return NULL;
            }
            int temp = arr[back];
            back = (back + 1) % capacity;
            if(back == (front + 1) % capacity)
            {
                back = -1;
                front = -1;
            }
            return temp;
        }

        ~CircularQueue()
        {
            delete[] arr;
        }
};