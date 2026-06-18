#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int val = 0)
        {   
            data = val;
            next = nullptr;
        }
};

class SinglyLinkedList
{
    private:
        Node* head;
    public:
        SinglyLinkedList()
        {
            head = nullptr;
        }
 
        void addNodeatStart(int val)
        {
            Node* newNode = new Node(val);

            if(head == nullptr)
            {
                head = newNode;
                return;
            }

            newNode->next = head;
            head = newNode;
        }

        void addNodeatEnd(int val)
        {
            Node* newNode = new Node(val);
            
            if(head == nullptr)
            {
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        void insertNode(int pos, int newVal)
        {
            if(head == nullptr)
            {
                cout << "List Empty." << endl;
                return;
            }

            Node* newNode = new Node(newVal);
            
            Node* curr = head;
            Node* prev = curr;

            for(int i = 0; i < pos; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = newNode;
            newNode->next = curr;
        }

        void removeFirstNode()
        {
            Node* temp = head;

            head = head->next;

            delete temp;
        }
        
        void removeLastNode() // class task
        {
            if(head == nullptr) // if no members
            {
                return;
            }

            if(head->next == nullptr) // if a single member
            {
                delete head;
                head = nullptr;

                return;
            }

            Node* temp = head;
            Node* prev = nullptr;

            while(temp->next != nullptr) // traverse to last
            {
                prev = temp;        // saves second last
                temp = temp->next;
            }

            prev->next = nullptr;
            delete temp;
        }
};
