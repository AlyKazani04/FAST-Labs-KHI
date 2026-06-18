#include <iostream>
using namespace std;

template <typename T>
class Queue // Circular
{
    private:
        T* arr; 
        int front, back;
        int capacity;
    public:
        Queue(int cap) : capacity(cap), front(-1), back(-1) 
        {
            arr = new T[capacity];
        }
        ~Queue(){ delete[] arr; }

        bool isFull(){ return (front + 1 % capacity) == back; }
        bool isEmpty(){ return front == -1; }

        void enqueue(T val)
        {
            if(isFull())
            {
                cout << "Queue is Full!" << endl;
                return;
            }
            if(isEmpty())
            {
                back = (back + 1) % capacity;
            }
            front = (front + 1) % capacity;
            arr[front] = val;
        }

        T dequeue()
        {
            if(isEmpty())
            {
                cout << "Queue is Empty" << endl;
                return NULL;
            }
            T temp = arr[back];
            back = (back + 1) % capacity;
            if(back == (front + 1) % capacity)
            {
                front = back = -1;
            }
            return temp;
        }
};

int main()
{
    Queue<char> C(5);

    C.enqueue('C');
    cout << C.dequeue() << endl;
    cout << C.dequeue() << endl;

    cout << C.isEmpty() << endl;
    
    return 0;
}