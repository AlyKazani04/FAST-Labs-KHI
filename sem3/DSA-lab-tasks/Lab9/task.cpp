#include <iostream>
using namespace std;

struct Folder
{
    int data;
    Folder* left;
    Folder* right;

    Folder(int val) : data(val), left(nullptr), right(nullptr) {}
};

int getHeightofFolder(Folder* root)
{
    if(!root) return 0;

    int leftHeight = getHeightofFolder(root->left);
    int rightHeight = getHeightofFolder(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int getBalanceFactor(Folder* root)
{
    int leftHeight = getHeightofFolder(root->left);
    int rightHeight = getHeightofFolder(root->right);

    int bf = leftHeight - rightHeight;

    return bf;
}

bool isSystemBalanced(Folder* root)
{
    if (!root) return true;

    int bf = getBalanceFactor(root);

    if(bf > 1 || bf < -1)
    {
        return false;
    }

    if(isSystemBalanced(root->left) == false)
    {
        return false;
    } 
    if(isSystemBalanced(root->right) == false)
    {
        return false;
    }

    return true;
}

int main()
{
    //      4
    //    2
    //      1
    Folder* root = new Folder(4);
    root->left = new Folder(2);
    root->left->right = new Folder(1);
    
    string res = (isSystemBalanced(root)) ? "Balanced" : "Unbalanced"; 
    cout << res << endl;

    delete root->left->right;
    delete root->left;
    delete root;

    //      2
    //    1   3
    root = new Folder(2);
    root->left = new Folder(1);
    root->right = new Folder(3);

    res = (isSystemBalanced(root)) ? "Balanced" : "Unbalanced"; 
    cout << res << endl;

    delete root->right;
    delete root->left;
    delete root;
    return 0;
}