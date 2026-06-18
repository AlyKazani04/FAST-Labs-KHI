#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    private:
        T* arr;
        int front;
        int back;
        const int capacity;
    public:
        Queue(int cap) : capacity(cap), front(-1), back(-1)
        {
            arr = new T[cap];
        }

        bool isFull()
        {
            return front == capacity - 1;
        }

        bool isEmpty()
        {
            return back == -1 && front == -1;
        }

        void enqueue(T val)
        {
            if(isFull())
            {
                cout << "Queue is full!" << endl;
                return;
            }
            if(isEmpty())
            {
                ++back;
            }
            arr[++front] = val;
        }

        T dequeue()
        {
            if(isEmpty())
            {
                cout << "Queue is empty!" << endl;
                return NULL;
            }
            T temp = arr[back];
            ++back;
            if(back > front)
            {
                back = -1;
                front = -1;
            }
            return temp;
        }

        ~Queue()
        {
            delete[] arr;
        }
};

int main()
{
    Queue<char> q(10);
    
    q.enqueue('g');
    q.enqueue('a');
    q.enqueue('y');

    while(!q.isEmpty())
    {
        cout << q.dequeue();
    }

    return 0;
}