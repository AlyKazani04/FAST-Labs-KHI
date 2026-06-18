#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int val): data(val), next(nullptr){}
};

class SinglyLinkedList
{
    private:
        Node* head;
    public:
        SinglyLinkedList() : head(nullptr){}

        void insertAtEnd(int val)
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

        void insertAtPosition(int val, int pos)
        {
            Node* newNode = new Node(val);
            if(pos == 0)
            {
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* temp = head;
            for(int i = 0; (i < pos - 1) && (temp != nullptr); i++)
            {
                temp = temp->next;
            }

            if(temp == nullptr)
            {
                cout << "Position out of bounds" << endl;
                delete newNode;
                return;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        void evenFirstSort()
        {
            if(head == nullptr || head->next == nullptr)
            {
                return;
            }
            
            Node* firstEven = nullptr;
            Node* lastEven = nullptr;
            Node* firstOdd = nullptr;
            Node* lastOdd = nullptr;

            Node* temp = head;

            while(temp != nullptr)
            {
                Node* nextNode = temp->next;
                temp->next = nullptr;

                if(temp->data % 2 == 0)
                {
                    if(firstEven == nullptr)
                    {
                        firstEven = temp;
                        lastEven = temp;
                    }
                    else
                    {
                        lastEven->next = temp;
                        lastEven = temp;
                    }

                }
                else
                {
                    if(firstOdd == nullptr)
                    {
                        firstOdd = temp;
                        lastOdd = temp;
                    }
                    else
                    {
                        lastOdd->next = temp;
                        lastOdd = temp; 
                    }
                }

                temp = nextNode;
            }

            if(lastEven != nullptr)
            {
                lastEven->next = firstOdd;
                head = firstEven;
            }
            else
            {
                head = firstOdd;
            }
        }

        void display()
        {
            Node* temp = head;
            
            while(temp != nullptr)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
};

int main()
{
    SinglyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    list.display();

    list.evenFirstSort();

    list.display();

    return 0;
}