#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BinarySearchTree
{
private:
    Node* root;

    Node* insert(Node* node, int val)
    {
        if(node == nullptr)
        {
            return new Node(val);
        }

        if(val < node->data)
        {
            node->left = insert(node->left, val);
        }

        if(val > node->data)
        {
            node->right = insert(node->right, val);
        }
    }
public:
    BinarySearchTree() : root(nullptr) {}

    void insertNode(int val)
    {
        root = insert(root, val);
    }

    Node* search(Node* node, int val)
    {
        if(node == nullptr || node->data == val)
        {
            return node;
        }
        if(val < node->data)
        {
            return search(node->left, val);
        }
        if(val > root->data)
        {
            return search(node->right, val);
        }
    }

    void printPreOrder(Node* node) const // VLR
    {
        if(node != nullptr)
        {
            cout << node->data << " ";
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
    }

    void printInOrder(Node* node) const // LVR
    {
        if(node != nullptr)
        {
            printInOrder(node->left);
            cout << node->data << " ";
            printInOrder(node->right);
        }
    }

    void printPostOrder(Node* node) const // LRV
    {
        if(node != nullptr)
        {
            printPostOrder(node->left);
            printPostOrder(node->right);
            cout << node->data << " ";
        }
    }

    Node* deleteNode(Node* node, int val)
    {
        if(node == nullptr)
        {
            return node;
        }

        if(val < node->data)
        {
            node->left = deleteNode(node->left, val);
        }
        else if(val > node->data)
        {
            deleteNode(node->right, val);
        }
        else 
        {
            if(node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if(node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return node;
    }

    Node* findMin(Node* node)
    {
        while(node && node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    ~BinarySearchTree()
    {
        
    }
};



int main()
{

    BinarySearchTree bst;

    bst.insertNode(5);
    bst.insertNode(3);
    bst.insertNode(2);
    bst.insertNode(4);
    bst.insertNode(6);

    return 0;
}