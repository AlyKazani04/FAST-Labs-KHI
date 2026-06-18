#include <iostream>
#include <vector>
using namespace std;

bool findSumSetRecursive(vector<int> arr, int target)
{
    if(target < 0) return false;
    if(target == 0) return true;
    if(arr.size() == 0) return false;

    for(int i = 0; i < arr.size(); i++)
    {
        vector<int> newArr = arr;
        newArr.erase(newArr.begin() + i);
        if(findSumSetRecursive(newArr, target - arr[i])) return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target  = 1;
    if(findSumSetRecursive(arr, target))
    {
        cout << "Found " << target << endl;
    }
    else{
        cout << "Not Found " << target << endl;
    }

    target = 6;
    if(findSumSetRecursive(arr, target))
    {
        cout << "Found " << target << endl;
    }
    else{
        cout << "Not Found " << target << endl;
    }

    target = 9;
    if(findSumSetRecursive(arr, target))
    {
        cout << "Found " << target << endl;
    }
    else{
        cout << "Not Found " << target << endl;
    }

    target = 37;
    if(findSumSetRecursive(arr, target))
    {
        cout << "Found " << target << endl;
    }
    else{
        cout << "Not Found " << target << endl;
    }
    return 0;
}