#include <iostream>
#include <vector>
using namespace std;

vector<string> parenthesisCombinations(int n, vector<string>& res, string curr = "", int open = 0, int close = 0)
{
    if(curr.length() == 2 * n) // equal ( and ) count
    {
        res.push_back(curr);
        return res;
    }

    if(open < n)
        parenthesisCombinations(n, res, curr + '(', open + 1, close); // add '(' if allowed
    
    if(close < open)
        parenthesisCombinations(n, res, curr + ')', open, close + 1); // add ')' if allowed
    
    return res;
}

int main()
{
    int n = 3;
    vector<string> combos; 

    parenthesisCombinations(n, combos);

    cout << "Possible combinations for 3 pairs: " << endl;
    for(auto& cmb : combos)
    {
        cout << cmb << endl;
    }
    
    combos.clear();

    n = 2;
    parenthesisCombinations(n, combos);

    cout << "Possible combinations for 2 pairs: " << endl;
    for(auto& cmb : combos)
    {
        cout << cmb << endl;
    }

    return 0;
}