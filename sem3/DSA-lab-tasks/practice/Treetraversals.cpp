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
void prefix(Node* root)         // Val -> Left -> Right
{
    if(root == nullptr) return;
    cout << root->val << " ";
    prefix(root->left);
    prefix(root->right);
}

void infix(Node* root)          // Left -> Val -> Right
{
    if(root == nullptr) return;
    infix(root->left);
    cout << root->val << " ";
    infix(root->right);    
}

void postfix(Node* root)        // Left -> Right -> Val
{
    if(root == nullptr) return;
    postfix(root->left);
    postfix(root->right);
    cout << root->val << " ";
}