#include <iostream>
using namespace std;

struct AvlNode
{
    int val;
    int height = 1;
    AvlNode* left;
    AvlNode* right;

    AvlNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Utils

int height(AvlNode* root)
{
    if(root == nullptr) return 0;
    return root->height;
}

int getBalance(AvlNode* root)
{
    if(root == nullptr) return 0;
    return height(root->left) - height(root->right);
}

void updateHeights(AvlNode* root)
{
    root->height = 1 + max(height(root->left), height(root->right));
}

// Rotations

AvlNode* rightRotate(AvlNode* b)  // old parent
{
    AvlNode* a = b->left;   // New Parent
    AvlNode* subtree = a->right;    // NewParent's right subtree
    
    a->right = b;   // New Parent's right points to old parent
    b->left = subtree;  // Old parent gets the New Parent's subtree

    updateHeights(b);   // Update child first
    updateHeights(a);

    return a;   // New root node of the rotation
}

AvlNode* leftRotate(AvlNode* a) // old parent
{
    AvlNode* b = a->right;  // new parent;
    AvlNode* subtree = b->left;

    b->left = a;
    a->right = subtree;

    updateHeights(a);
    updateHeights(b);

    return b;   // New root node of the rotation
}

// Insertion

AvlNode* insert(AvlNode* root, int key)
{
    if(root == nullptr) return new AvlNode(key);

    if(key < root->val)
    {
        root->left = insert(root->left, key);
    }
    else if(key > root->val)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    updateHeights(root);

    int balance = getBalance(root);

    // Left Left
    if(balance > 1 && key < root->left->val)
    {
        return rightRotate(root);
    }
    
    // Right Right
    if(balance < -1 && key > root->right->val)
    {
        return leftRotate(root);
    }

    // Left RIght
    if(balance > 1 && key > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if(balance < -1 && key < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool AvlSearch(AvlNode* root, int key)
{
    if(root == nullptr) return false;
    if(root->val == key)    return true;

    return (key < root->val) ? AvlSearch(root->left, key) : AvlSearch(root->right, key);
}

int main()
{
    

    return 0;
}