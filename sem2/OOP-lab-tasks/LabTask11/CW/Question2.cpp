#include <iostream>
#include <string>
#include <exception>
#include <vector>
using namespace std;

class dimensionMismatchException : public exception{ // custom exception
    public:
        const char* what() const noexcept override{
            return "DimensionMismatchError : Dimensions of the matrices do not match.";
        }
};

template<class T>
class Matrix{
    private:
        size_t rows,cols;
        vector<vector<T>> stuff;
    public:
        Matrix(size_t r, size_t c, const T& initial = T() )/* default empty data type, e.g: empty string, 0, 0.0 etc.*/ : 
            rows(r), cols(c), stuff(r) {
                for(auto& row : stuff){
                    row.resize(c, initial);
                }
            }

        T at(size_t r, size_t c) const{
            if(r >= rows || c >= cols){
                throw out_of_range("Entered Matrix index was out of bounds.");
            }
            return stuff[r][c];
        }

        size_t getrows() const{ return rows; }
        size_t getcolumns() const{ return cols; }

        Matrix operator+(const Matrix& other) const{
            if(rows != other.rows || cols != other.cols){
                throw dimensionMismatchException();
            }

            Matrix result(rows, cols); // temp mat of same dimensions
            for(int i = 0; i < rows; i++){
                for(int j = 0 ; j < cols; j++){
                    result.stuff[i][j] = stuff[i][j] + other.stuff[i][j];
                }
            }
            return result;
        }

        Matrix operator*(const Matrix& other) const{
            if(cols != other.rows){
                throw dimensionMismatchException();
            }

            Matrix result(rows, other.cols, T());
            for(int i = 0; i < rows ; i++){
                for(int j = 0; j < other.cols; j++){
                    for(int k = 0; k < cols; k++){
                        result.stuff[i][j] += stuff[i][k] * other.stuff[k][j];
                    }
                }
            }
            return result;
        }

        void print() const{
            for(const auto& row : stuff){
                for(const auto& val : row){
                    cout<<val<<" ";
                }
                cout<<"\n";
            }
        }
};

int main(){

    try {
        Matrix<int> A(2, 3, 1); // 2x3 mat filled with 1s
        Matrix<int> B(2, 3, 2); // 2x3 mat filled with 2s
        Matrix<int> C = A + B; // out: 2x3 mat filled with 3s

        cout<<"A + B:"<<endl;
        C.print();

        Matrix<int> D(3, 2, 1); // 3x2 mat filled with 1s
        Matrix<int> E = A * D;  // out: 2x2 mat filled with 3s 

        cout<<"A * D:"<<endl;
        E.print();

        // Safe access
        cout<<"Element at (0,1): "<<C.at(0, 1)<<endl; // C : filled with 1s

        // Out of bounds access
        cout<<C.at(5, 5)<<endl;
    } 
    catch(const dimensionMismatchException& e){
        cerr<<e.what()<<endl;
    } 
    catch(const std::exception& e){
        cerr<<"Exception: "<<e.what()<<endl;
    }

    return 0;
}