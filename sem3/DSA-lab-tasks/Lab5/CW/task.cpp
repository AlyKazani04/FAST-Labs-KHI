#include <iostream>
using namespace std;

void display(int** arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
        {   
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int** arr, int x, int y, int n)
{
    if(x >= 0 && y >=0 && x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratInMaze(int** arr, int x, int y, int n, int** solArr)
{   
    if(x < 0 || y < 0 || x >= n || y >= n) return false;

    if(x == (n-1) && y == (n-1)) // goal condition, bottom-right cell
    {
        solArr[x][y] = 1;
        return true;
    }

    if(isSafe(arr, x, y, n))
    {
        solArr[x][y] = 1;
        
        if(ratInMaze(arr, x + 1, y, n, solArr))
        {
            return true;
        }
        if(ratInMaze(arr, x, y + 1, n, solArr))
        {
            return true;
        }

        solArr[x][y] = 0; // backtracking
        return false;
    }
    return false;
}

int main()
{
    int n = 4;
    
    int** arr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    arr[0][0] = 1; arr[0][1] = 0; arr[0][2] = 0; arr[0][3] = 0;
    
    arr[1][0] = 1; arr[1][1] = 1; arr[1][2] = 0; arr[1][3] = 1;
    
    arr[2][0] = 0; arr[2][1] = 1; arr[2][2] = 0; arr[2][3] = 0;
    
    arr[3][0] = 1; arr[3][1] = 1; arr[3][2] = 1; arr[3][3] = 1;

    int** solArr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        solArr[i] = new int[n]();
    }

    cout << "Maze: " << endl;

    display(arr, 4);

    ratInMaze(arr, 0, 0, 4, solArr);


    cout << endl << "Solution: " << endl;
    display(solArr, 4);

    for(int i = 0; i < n; i++) 
    {
        delete[] arr[i];
        delete[] solArr[i];
    }

    delete[] arr;
    delete[] solArr;

    return 0;
}