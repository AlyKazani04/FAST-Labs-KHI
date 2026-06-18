#include <bits/stdc++.h>
using namespace std;

class Matrix{
	int rows;
	int columns;
	int **elements;
	public:
		Matrix(int x, int y){
			rows = x;
			columns = y;
			elements = new int*[rows];
			for(int i = 0 ; i < rows ; i++){
				elements[i] = new int[columns];
			}
			
		}
		int getrows(){
			return rows;
		}
		int getcolumns(){
			return columns;
		}
		int getelement(int i, int j){
			return elements[i][j];
		}
		void setelement(int i, int j, int a){
			if( i < rows && j < columns){
				elements[i][j] = a;
			}
			else{
				cout<<"Invalid position."<<endl;
			}
		}
		void display(){
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
					cout<<elements[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
		Matrix addmatrix(const Matrix& a){
			if(a.rows == rows && a.columns == columns){
				Matrix result(rows, columns);
				for(int i = 0; i < rows; i++){
					for(int j = 0; j < columns; j++){
						result.elements[i][j] = elements[i][j] + a.elements[i][j];
					}
				}
				return result;
			}
			else{
				cout<<"Matrices cannot be added"<<endl;
				return Matrix(0,0);
			}
		}
		Matrix multiplymatrix(const Matrix& a){
			if(columns != a.rows){
				cout<<"Matrix multiplication not possible."<<endl;
				return Matrix(0,0);
			}
			Matrix result(rows, a.columns);
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < a.columns; j++){
					result.elements[i][j] = 0;
					for(int k = 0; k < columns; k++){
						result.elements[i][j] += elements[i][k] * a.elements[k][j];
					}
				}
			}
			return result;
		}
};

int main(int argc, char** argv){
	Matrix A(2, 2);
	A.setelement(0, 0, 1);
	A.setelement(0, 1, 2);
	A.setelement(1, 0, 3);
	A.setelement(1, 1, 4);
	
	Matrix B(2, 2);
	B.setelement(0, 0, 1);
	B.setelement(0, 1, 2);
	B.setelement(1, 0, 1);
	B.setelement(1, 1, 4);
	
	cout<<"Matrix A:"<<endl;
	A.display();
	
	cout<<"Matrix B:"<<endl;
	B.display();
	
	Matrix C = A.addmatrix(B);
	cout<<"Matrix A + B:"<<endl;
	C.display();
	
	Matrix D = A.multiplymatrix(B);
	cout<<"Matrix A * B:"<<endl;
	D.display();
    
	return 0;
}