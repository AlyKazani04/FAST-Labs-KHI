#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int val = 0): data(val), prev(nullptr), next(nullptr) {}
};

class CircularDoubleList
{
    private:
        Node* head;
        Node* tail;
    public:
        CircularDoubleList()  : head(nullptr), tail(nullptr) {}

        void insertAtEnd(int val)
        {
            Node* newNode = new Node(val);

            if(head == nullptr)
            {
                head = newNode;
                tail = newNode;
                tail->prev = head;
                tail->next = head;
                return;
            }    

            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            tail = tail->next;
            head->prev = tail;
        }

        void insertAtStart(int val)
        {
            Node* newNode = new Node(val);
            
            if(head == nullptr)
            {
                head = newNode;
                tail = newNode;
                tail->prev = head;
                tail->next = head;
                return;
            }
            
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            head = head->prev;
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

            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
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
                head->prev = tail;
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
            temp->next->prev = prev;
            delete temp;
        }

        void display()
        {
            if(head == nullptr)
            {
                cout << "List is empty!" << endl;
                return;
            }
            
            cout << "Head: ";
            
            Node* temp = head;
            do
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }while(temp != head);
            
            cout << "Back to Head" << endl;

            cout << "Tail: ";

            temp = tail;
            do
            {
                cout << temp->data << " -> ";
                temp = temp->prev;
            }while(temp != tail);

            cout << "Back to Tail" << endl;
        }
};

int main()
{

    CircularDoubleList circdb;

    circdb.insertAtStart(1);
    circdb.insertAtEnd(2);
    circdb.insertAtPosition(3, 1);

    circdb.display();
    
    circdb.deleteNode(1);

    circdb.display();

    return 0;
}