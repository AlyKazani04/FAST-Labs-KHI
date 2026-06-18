#include <iostream>
using namespace std;

struct Node
{
    int val;
    int priority;
    Node* next;
    Node(int v, int p) : val(v), priority(p), next(nullptr) {}
};

class priorityqueue
{
    private:
        Node* front;
    public:
        priorityqueue(): front(nullptr) {}
        ~priorityqueue()
        {
            while(front != nullptr)
            {
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        void insert(int val, int pri)
        {
            Node* newNode = new Node(val, pri);

            if(front == nullptr || pri > front->priority)
            {
                newNode->next = front;
                front = newNode;
            }
            else
            {
                Node* curr = front;
                while(curr->next && pri <= curr->next->priority)
                {
                    curr = curr->next;
                }
                newNode->next = curr->next;
                curr->next = newNode;
            }
        }

        void dispatch()
        {
            if(front == nullptr)
            {
                cout << "Queue is empty!" << endl;
                return;
            }
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        int peek()
        {
            int res = (front != nullptr) ? front->val : -1;
            return res;
        }

        void printQueue()
        {
            if(front == nullptr)
            {
                cout << "Queue is empty!" << endl;
                return;
            }
            Node* temp = front;
            while(temp != nullptr)
            {
                cout << "(" << temp->val << ", " << temp->priority << ") ";
            }
            cout << endl;
        }
};
