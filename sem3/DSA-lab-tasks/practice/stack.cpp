#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    private:
        int top;
        T* arr;
        int capacity;
    public:
        Stack(int cap) : capacity(cap), top(-1)
        {
            arr = new T[capacity];
        }

        ~Stack()
        {
            delete[] arr;
        }

        bool isEmpty(){ return top == -1; }
        bool isFull(){ return top == capacity - 1; }
        T peek(){ return arr[top]; }

        bool push(T val)
        {
            if(isFull())
            {
                cout << "Stack Full!" << endl;
                return false;
            }
            arr[++top] = val;
            return true;
        }

        T pop()
        {
            if(isEmpty())
            {
                cout << "Stack Empty!" << endl;
                return NULL;
            }
            return arr[top--];
        }
};

int main()
{
    Stack<char> st(4);

    st.push('G');
    st.push('\'');
    cout << "Popped: " << st.pop() << endl;
    cout << st.peek() << endl;
    cout << st.isEmpty() << endl;
    st.pop();
    cout << st.isEmpty() << endl;
    
    return 0;
}