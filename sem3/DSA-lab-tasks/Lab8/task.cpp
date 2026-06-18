#include <iostream>
using namespace std;

class Student
{
    public:
        string rollno;
        string name;
        int score;
        
        Student(string rn, string n, int sc) : rollno(rn), name(n), score(sc), 
            left(nullptr), right(nullptr) {}

        Student* left;
        Student* right;
};

class BinarySearchTree
{
    private:
        Student* root;

        Student* insert(Student* node, string rollno, string name, int score)
        {
            if(node == nullptr)
            {
                return new Student(rollno, name, score);
            }

            if(score < node->score)
            {
                node->left = insert(node->left, rollno, name, score);
            }

            if(score > node->score)
            {
                node->right = insert(node->right, rollno, name, score);
            }
        }

        Student* findLessThan10(Student* node)
        {
            if(!node)
            {
                return nullptr;
            }

            if(node->score < 10)
            {
                return node;
            }

            Student* temp = findLessThan10(node->left);
            if(temp)
            {
                return temp;
            }

            return findLessThan10(node->right);
        }
    public:

        BinarySearchTree() : root(nullptr) {}

        void insertNode(string rollno, string name, int score)
        {
            root = insert(root, rollno, name, score);
        }

        void deleteLessThan10(Student* node)
        {
            Student* temp;
            while(temp = deleteNode(node, 10))
            {
                cout << "Deleted " << temp->rollno << endl;
            }
        }

        Student* deleteNode(Student* node, int score)
        {
            if(node == nullptr)
            {
                return node;
            }

            if(score < node->score)
            {
                node->left = deleteNode(node->left, score);
            }
            else if(score > node->score)
            {
                deleteNode(node->right, score);
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
                    Student* temp = node->right;
                    delete node;
                    return temp;
                }
                else if(node->right == nullptr)
                {
                    Student* temp = node->left;
                    delete node;
                    return temp;
                }
                Student* temp = findLessThan10(root->right);
                root->rollno = temp->rollno;
                root->name = temp->name;
                root->score = temp->score;
                root->right = deleteNode(root->right, temp->score);
            }
            return node;
        }

        
};

int main()
{   

    return 0;
}