#include <iostream>
#include <cmath>
using namespace std;

class Polynomial{
	int degree;
	double* coefficients;
	public:
		//def constr
		Polynomial(){
			degree = 0;
			coefficients = new double{0};
		}//para constr
		Polynomial(int deg, const double co_array[]){
			degree = deg;
			coefficients = new double[degree + 1];
			for(int i = 0; i <= degree; i++){
				coefficients[i] = co_array[i]; 
			}
		}
		//copy
		Polynomial(const Polynomial& other) : degree(other.degree){
			coefficients = new double[degree + 1];
			for(int i = 0; i <= degree; i++){
				coefficients[i] = other.coefficients[i];
			}
		}
		//move
		Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients){
			other.coefficients = nullptr;
			other.degree = 0;
		}
		//destr
		~Polynomial(){
			delete[] coefficients;
		}
		//selfexplanatory
		int getdegree(){
			return degree;
		}
		double evaluate(double x) const{
			double result = 0;
			for(int i = 0; i<= degree; i++){
				result += coefficients[i] * pow(x,i);
			}
			return result;
		}
		Polynomial add(const Polynomial& other) const{
			int maxdegree = max(degree, other.degree);
			double* re_coeff = new double[maxdegree + 1]{0};
			for(int i = 0; i<= degree; i++){
				re_coeff[i] += coefficients[i];
			}
			for(int j = 0; j <= other.degree; j++){
				re_coeff[j] += other.coefficients[j];
			}
			Polynomial result(maxdegree, re_coeff);
			return result;
		}
		Polynomial multiply(const Polynomial& other) const{
			int re_degree = degree + other.degree;
			double* re_coeff = new double[re_degree + 1]{0};
			for(int i = 0; i<= degree; i++){
				for(int j = 0; j <= other.degree; j++){
					re_coeff[i + j] += coefficients[i] * other.coefficients[j];
				}
			}
			Polynomial result(re_degree, re_coeff);
			return result;
		}
		void display() const{
			for(int i = degree; i >= 0; i--){
				cout<<coefficients[i];
				if(i > 0)	cout<<"x^"<<i;
				(i > 0) ? cout<<" + " : cout<<endl;
			}
		}
};

int main(int argc, char** argv){
	double coeffs1[] = {1, 2, 3};//1 + 2x + 3x^2
	Polynomial p1(2, coeffs1);
	p1.display();
	
	double coeffs2[] = {4, 5}; //4 + 5x
    Polynomial p2(1, coeffs2);
    p2.display();

    Polynomial sum = p1.add(p2);
    sum.display();

    Polynomial product = p1.multiply(p2);
    product.display();
	return 0;
}
