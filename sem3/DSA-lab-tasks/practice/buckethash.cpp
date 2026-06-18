#include <iostream>
using namespace std;

struct Node
{
    int key;
    int val;
    Node* next;
    Node(int k, int v) : key(k), val(v), next(nullptr) {}
};

class HashTable
{
    private:
        Node* buckets[10];

        int hash(int key)
        {
            return key % 10;
        }
    public:
        HashTable()
        {
            for(int i = 0; i < 10; i++)
            {
                buckets[i] = nullptr;
            }
        }
        ~HashTable()
        {
            for(int i = 0; i < 10; i++)
            {
                while(buckets[i] != nullptr);
                {
                    Node* temp = buckets[i];
                    buckets[i] = buckets[i]->next;
                    delete temp;
                }
            }
            delete[] buckets;
        }

        void insert(int key, int val)
        {
            int index = hash(key);
            Node* newNode = new Node(key, val);

            if(buckets[index] == nullptr)
            {
                buckets[index] = newNode;
            }
            else
            {
                if(search(newNode->key) == -1)
                {
                    newNode->next = buckets[index];
                    buckets[index] = newNode;
                }
                else
                {
                    cout << "Item already exists" << endl;
                }
            }
        }

        int search(int key)
        {
            int index = hash(key);
            Node* temp = buckets[index];

            while(temp != nullptr)
            {
                if(temp->key == key)
                {
                    return temp->val;
                }
                temp = temp->next;
            }
            return -1;
        }

        int remove(int key)
        {
            int index = hash(key);
            Node* temp = buckets[index];
            Node* prev = nullptr;

            while(temp != nullptr && temp->key != key)
            {
                prev = temp;
                temp = temp->next;
            }
            if(temp == nullptr)
            {
                cout << "Key " << key << " not found!" << endl;
                return -1;
            }
            if(prev == nullptr)
            {
                buckets[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Key: " << key << " deleted!" << endl;
        }
};