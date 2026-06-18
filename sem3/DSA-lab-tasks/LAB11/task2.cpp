#include <bits/stdc++.h>
using namespace std;

void insertPost(unordered_set<string>& table, string post)
{
    if(table.emplace(post).second)
    {
        cout << "NEW" << endl;
    }
    else
    {
        cout << "DUPLICATE" << endl;
    }
}

int main()
{
    unordered_set<string> postsTable;
    
    int choice;
    string post;
    bool isRunning = true;

    while(isRunning)
    {
        cout << "Choices\nInsert Post => 1\nExit => 0\n";
        cout << "Enter Choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice)
        {
            case 1:
                cout << "Enter Post Text: ";
                getline(cin, post);
                if(cin.fail() || post.empty())
                {
                    cerr << "Invalid or empty string input. Try Again" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cout << endl;
                insertPost(postsTable, post);
                cout << endl;
                break;
            case 0:
                isRunning = false;
                break;
            default: 
                cout << "Invalid choice! Choose 1 or 0" << endl;
                break;
        }
    }

    return 0;
}