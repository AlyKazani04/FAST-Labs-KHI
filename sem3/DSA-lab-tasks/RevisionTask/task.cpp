#include <iostream>
using namespace std;

struct Node
{
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
        Node(const Node& other)
        {
            data = other.data;
            next = other.next;
        }
};

class Stack
{
    private:
        Node* m_top = nullptr;
        int currSize = 0;
    public:
        Stack() =default;
        ~Stack()
        {
            while(!isEmpty())
            {
                pop();
            }
        }

        void push(const int& val)
        {
            Node* newNode = new Node(val);
            newNode->next =  m_top; 
            m_top = newNode;

            currSize++;
        }
        int pop()
        {
            if(isEmpty())
            {
                cerr << "Stack Underflow!" << endl;
                return -1;
            }
                Node* temp = m_top;
                
                int val = temp->data;
                m_top = m_top->next;
                delete temp;
                currSize--;

                return val;
        }

        bool isEmpty() const
        {
            return (m_top == nullptr);
        }
        int peek()
        {
            if(!isEmpty())
                return m_top->data;
            else
                return -1;
        }
        int getSize()
        {
            return currSize;
        }
};

class Queue 
{
    private:
        int currSize;
        Node* front;
        Node* rear;
    public:
        Queue() : currSize(0) 
        {
            front = rear= NULL;
        }

        bool isEmpty() 
        {
            return front == NULL;
        }

        void enqueue(int new_data) 
        {
            Node* node = new Node(new_data);
            if (isEmpty()) {
                front = rear = node;
            } else {
                rear->next = node;
                rear = node;
            }
            
            currSize++;
        }

        int dequeue()
        {
            if (isEmpty()) {
                cout << "Queue Underflow" << endl;
                return -1;
            }
            
            Node* temp = front;
            int removedData = temp->data;
            front = front->next;
            
            if (front == NULL) rear = NULL;
            delete temp;
            
            currSize--;
            return removedData;
        }

        int getfront() 
        {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            return front->data;
        }

        int getSize() 
        {
            return currSize;
        }
};

class Structure
{
    private:
        Stack st;
        Queue q;
        bool parity = true; // true == even, false == odd
        int totalSize = 0;

        void switchParity()
        {
            if(parity == false) // stack to queue
            {
                Stack temp;

                while(!st.isEmpty())
                {
                    temp.push(st.pop());
                }

                while(!temp.isEmpty())
                {
                    q.enqueue(temp.pop());
                }


                parity = true;
            }
            else // queue to stack mode
            {
                Queue temp;

                int size = q.getSize();
                while(!q.isEmpty())
                {
                    temp.enqueue(q.dequeue());
                }

                while(!temp.isEmpty())
                {
                    st.push(temp.dequeue());
                }

                parity = false;
            }
        } 
    public:
        void insert(const int val)
        {
            if(parity == true) // insert in queue
            {
                q.enqueue(val);
                switchParity();
            }
            else
            {
                st.push(val);
                switchParity();
            }
            totalSize++;
        }

        Node remove()
        {
            Node t(0);
            if(parity == true)
            {
                int temp = q.dequeue();
                t.data = temp;
                switchParity();
            }
            else
            {
                int temp = st.pop();
                t.data = temp;
                switchParity();
            }
            totalSize--;
            return t;
        }

        int view()
        {
            if(parity == true)
            {
                int temp = q.getfront();
                return temp;
            }
            else
            {
                int temp = st.peek();
                return temp;
            }
        }
};

int main()
{   
    Structure st;

    st.insert(5);
    cout << "Inserted 5, viewing: " << st.view() << endl;
    st.insert(6);
    cout << "Inserted 6, viewing: " << st.view() << endl;
    st.insert(7);
    cout << "Inserted 7, viewing: " << st.view() << endl;

    Node retval(st.remove());

    cout << "Removed " << retval.data << ", viewing: " << st.view() << endl;

    Node nextremove(st.remove());

    cout << "Removed " << nextremove.data << ", viewing: " << st.view() << endl;

    st.insert(10);
    cout << "Inserted 10, viewing: " << st.view() << endl;

    return 0;
}