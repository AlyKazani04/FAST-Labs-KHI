#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int val = 0): data(val), next(nullptr) {}
};

class CircularList
{
    private:
        Node* head;
        Node* tail;
    public:
        CircularList()  : head(nullptr), tail(nullptr) {}

        void insertAtEnd(int val)
        {
            Node* newNode = new Node(val);

            if(head == nullptr)
            {
                head = newNode;
                tail = newNode;
                tail->next = head;
                return;
            }    

            newNode->next = head;
            tail->next = newNode;
            tail = tail->next;
        }

        void insertAtStart(int val)
        {
            Node* newNode = new Node(val);
            
            if(head == nullptr)
            {
                head = newNode;
                tail = newNode;
                tail->next = head;
                return;
            }
            
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }

        void insertAtPosition(int val, int pos)
        {
            if(pos == 0)
            {
                insertAtStart(val);
                return;
            }

            Node* newNode = new Node(val);
            Node* temp = head;

            for(int i = 0; i < pos - 1; i++)
            {

                if(temp->next == head)
                {
                    cout << "Error: Position is out of bounds!" << endl;
                    delete newNode;
                    return;
                }
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode; 

            if(temp == tail)
            {
                tail = newNode;
            }
        }

        void deleteNode(int pos)
        {
            if(head == nullptr)
            {
                cout << "List empty!" << endl;
                return;
            }

            if(pos == 0)
            {
                Node* temp = head;
                
                head = head->next;
                tail->next = head;

                delete temp;
                return;
            }

            Node* temp = head;
            Node* prev = nullptr;
            for(int i = 0; i < pos; i++)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = temp->next;
            delete temp;
        }

        void display()
        {
            if(head == nullptr)
            {
                cout << "List is empty!" << endl;
                return;
            }
            
            Node* temp = head;
            do
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }while(temp != head);

            cout << "Back to Head" << endl;
        }
};


int main()
{
    CircularList circ;

    circ.insertAtStart(1);
    circ.insertAtEnd(2);
    circ.insertAtPosition(3, 1);

    circ.display();
    
    circ.deleteNode(1);

    circ.display();

    return 0;
}