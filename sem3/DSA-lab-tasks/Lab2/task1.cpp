#include <iostream>
using namespace std;

class DynamicMatrix{
    private:
        int** matrix;
        int rows;
        int cols;
    public:
        DynamicMatrix(){
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            
            matrix = new int*[rows];

            for(int i = 0; i < rows; i++){
                matrix[i] = new int[cols];
            }

            input();
        }

        void input(){
            cout << "Enter matrix elements: " << endl;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cout << "Element [" << i << "][" << j << "]: ";
                    cin >> matrix[i][j];
                }
            }
        }

        void resize(int nrows, int ncols, int val = 0){
            // new matrix
            int** newMatrix = new int*[nrows];
            for(int i = 0; i < nrows; i++){
                newMatrix[i] = new int[ncols];
            }

            // copy old matrix
            int temprows = (nrows < rows) ? nrows : rows;
            for(int i = 0; i < temprows; i++){
                int tempcols = (ncols < cols) ? ncols : cols;

                for(int j = 0; j < tempcols; j++){
                    newMatrix[i][j] = matrix[i][j];
                }
            }

            // fill new cells with val
            if(nrows > rows){
                for(int i = rows; i < nrows; i++){
                    for(int j = 0; j < ncols; j++){
                        newMatrix[i][j] = val;
                    }
                }
            }
            if(ncols > cols){
                for(int i = 0; i < nrows; i++){
                    for(int j = cols; j < ncols; j++){
                        newMatrix[i][j] = val;
                    }
                }
            }

            // delete old matrix
            for(int i = 0; i < rows; i++){
                delete[] matrix[i];
            }
            delete[] matrix;

            matrix = newMatrix;
            rows = nrows;
            cols = ncols;
        }

        void transpose(){
            int** newMatrix = new int*[cols];
            for(int i = 0; i < cols; i++){
                newMatrix[i] = new int[rows];
            }
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    newMatrix[i][j] = matrix[j][i];
                }
            }
            for(int i = 0; i < rows; i++){
                delete[] matrix[i];
            }
            delete[] matrix;

            matrix = newMatrix;
            int temp = rows;
            rows = cols;
            cols = temp;
        }

        void display(){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cout << matrix[i][j] << ' '; 
                }
                cout << endl;
            }
        }

        void add2ToOddIndex(){
            for(int  i = 0; i < rows; i++){
                for(int j = 0; j <cols; j++){
                    if(i % 2 != 0 || j % 2 != 0){
                        matrix[i][j] += 2;
                    }
                }
            }

            display();
        }

        void add2ToOddValue(){
            for(int  i = 0; i < rows; i++){
                for(int j = 0; j <cols; j++){
                    if(matrix[i][j] % 2 != 0){
                        matrix[i][j] += 2;
                    }
                }
            }

            display();
        }
        ~DynamicMatrix(){
            for(int i = 0; i < rows; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
        }
};

int main(){
    DynamicMatrix dynamat;

    dynamat.display();

    cout << "Resized to 3x3 Matrix, used 7 to fill new cells: " << endl;
    dynamat.resize(3, 3, 7);
    dynamat.display();

    cout << "Transpose of Matrix: " << endl;
    dynamat.transpose();
    dynamat.display();

    cout << "Add 2 to odd indices(if either i or j in [i][j] is odd): " << endl;
    dynamat.add2ToOddIndex();

    cout << "Add 2 to odd Value(if the value in [i][j] is odd): " << endl;
    dynamat.add2ToOddValue();
    return 0;
}