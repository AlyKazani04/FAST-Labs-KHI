#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Traversals 
void prefix(Node* root)
{
    if(root == nullptr) return;
    cout << root->val << " ";
    prefix(root->left);
    prefix(root->right);
}

void infix(Node* root)
{
    if(root == nullptr) return;
    infix(root->left);
    cout << root->val << " ";
    infix(root->right);    
}

void postfix(Node* root)
{
    if(root == nullptr) return;
    postfix(root->left);
    postfix(root->right);
    cout << root->val << " ";
}

// utilities

Node* search(Node* root, int key)
{
    if(root == nullptr || root->val == key)
    {
        return root;
    }
    if(key < root->val)
    {
        return search(root->left, key);
    }
    if(key > root->val)
    {
        return search(root->right, key);
    }
    return root;
}

Node* insertion(Node* root, int key)
{
    if(root == nullptr)
    {
        return new Node(key);
    }
    if(key < root->val)
    {
        root->left = insertion(root->left, key);
    }
    else
    {
        root->right = insertion(root->right, key);
    }
    return root;
}

Node* findMin(Node* root)
{
    if(root->left == nullptr) return root;
    return findMin(root->left);
}

Node* deleteNode(Node* root, int key)
{
    if(root == nullptr)
    {
        return root;
    }

    if(key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if(root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if(root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main()
{

    Node* tree = nullptr;
    tree = insertion(tree, 5);
    insertion(tree, 7);
    insertion(tree, 4);
    insertion(tree, 3);

    cout << "Infix: ";
    infix(tree);
    cout << endl;

    cout << "Prefix: ";
    prefix(tree);
    cout << endl;
    
    cout << "Postfix: ";
    postfix(tree);
    cout << endl;

    deleteNode(tree, 3);
    deleteNode(tree, 7);
    deleteNode(tree, 4);
    deleteNode(tree, 5);

    return 0;
}