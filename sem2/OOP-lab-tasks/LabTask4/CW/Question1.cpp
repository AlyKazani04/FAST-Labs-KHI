#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Matrix{
	int rows;
	int cols;
	int** elements;
	public:
//		default constructor
		Matrix(){
			rows = 0;
			cols = 0;
			elements = new int*[rows];
			elements[0] = new int[cols];
		}
//		parameterized
		Matrix(int r=0, int c=0) : rows(r), cols(c){
			elements = new int*[rows];
			for(int i = 0; i < rows; i++){
				elements[i] = new int[cols];
				for(int j = 0; j<cols; j++){
					elements[i][j]=0;
				}
			}
		}
//		copy constructor
		Matrix(const Matrix& other){
			rows = other.rows;
			cols = other.cols;
			elements = new int*[rows];
			for(int i = 0; i < rows; i++){
				elements[i] = new int[cols];
				for(int j = 0; j < cols; j++){
					elements[i][j] = other.elements[i][j];
				}
			}
		}
//		move constructor
		Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), elements(other.elements){
			other.rows = 0;
			other.cols = 0;
			other.elements = nullptr;
		}
//		destructor
		~Matrix(){
			for(int i = 0; i<rows; i++){
				delete[] elements[i];
			}
			delete[] elements;
		}
		void setelement(int r, int c, int val){
			elements[r][c] = val;
		}
		int getrows(){
			return rows;
		}
		int getcols(){
			return cols;
		}
		int* at(int r, int c){
			int *elementptr = &elements[r][c];
			return elementptr;
		}  
		void fill(int val){
			for(int i = 0; i < getrows(); i++){
				for(int j = 0; j < getcols(); j++){
					elements[i][j] = val;
				}
			}
		}
		Matrix transpose(){
			Matrix newmat(cols, rows);
			for(int i = 0; i < newmat.rows; i++){
				for(int j = 0; j < newmat.cols; j++){
					newmat.elements[i][j] = elements[j][i];
				}
			}
			cout<<"Current Matrix"<<endl;
			display();
			cout<<"Transpose of new matrix:"<<endl;
			newmat.display();
			return newmat;
		}
		void display(){
			for(int i = 0; i < rows; i++){
				for(int j = 0; j < cols; j++){
					cout<<elements[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};

int main(int argc, char** argv){
	Matrix mat1(2 , 3);
	Matrix mat2(mat1);
	mat1.display();
	cout<<endl;
	mat2.fill(4);
	mat2.display();
	int count = 0;
	for(int i = 0; i<mat1.getrows(); i++){
		for(int j = 0 ; j<mat1.getcols();j++){
			count++;
			mat1.setelement(i,j,count);
		}
	}
	cout<<endl;
	mat1.display();
	Matrix mat3 = mat1.transpose();
	return 0;
}