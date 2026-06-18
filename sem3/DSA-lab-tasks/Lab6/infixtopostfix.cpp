#include <iostream>
#include <cstring>
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

        T peek()
        {
            if(isEmpty())
            {
                cout << "Stack is empty" << endl;
                return NULL;
            }
            return arr[top];
        }

        ~Stack()
        {
            delete[] arr;
        }
};

bool isOperator(char ch)
{
    return ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^';
}

int precedence(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }
    if(op == '*' || op == '/')
    {
        return 2;
    } 
    if(op == '^')
    {
        return 3;
    }
    return 0;
}

bool powerOperatorCheck(char op)
{
    return op == '^';
}

string infixToPostfix(string infix)
{
    Stack<char> stack(infix.length());
    string postfix = "";

    for(char c : infix)
    {
        if(isalnum(c))
        {
            postfix += c;
        }
        else if(c == '(')
        {
            stack.push(c);
        }
        else if(c == ')')
        {
            while(!stack.isEmpty() && isOperator(stack.peek()))
            {
                postfix += stack.pop();
            }
            if (!stack.isEmpty() && stack.peek() == '(')
            {
                stack.pop();
            }
        }
        else if(isOperator(c))
        {
            while (!stack.isEmpty() && isOperator(stack.peek()) && (precedence(c) <= precedence(stack.peek()) 
                && !(powerOperatorCheck(c) && precedence(c) > precedence(stack.peek()))))
            {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    while(!stack.isEmpty())
    {
        postfix += stack.pop();
    }

    return postfix;
}


int main()
{
    string infix;
    cout << "Enter infix: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}