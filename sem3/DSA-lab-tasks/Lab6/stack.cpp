#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    private:
        T* arr;
        int top;
        const int capacity;
    public:
        Stack(int cap) : capacity(cap), top(-1)
        {
            arr = new T[cap];
        }

        void push(T val)
        {
            if(isFull())
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            arr[++top] = val;
        }

        T pop()
        {
            if(isEmpty())
            {
                cout << "Stack Underflow" << endl;
                return NULL;
            }
            T temp = arr[top];
            --top;
            return temp;
        }

        bool isFull()
        {
            return top == capacity - 1;
        }

        bool isEmpty()
        {
            return top == -1;
        }

        void peek()
        {
            cout << arr[top] << endl;
        }

        ~Stack()
        {
            delete[] arr;
        }
};

int main()
{  
    Stack<char> stack(10);

    stack.push('y');
    stack.push('a');
    stack.push('g');
    string res = "";

    while(!stack.isEmpty())
    {
        res += stack.pop();
    }

    cout << res << endl;
    return 0;
}