#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Polynomial{
	private:
		vector<int> coeff;
		void trim(){
			while(!coeff.empty() && coeff.back() == 0){
				coeff.pop_back();
			}
		}
	public:
		Polynomial(){
			coeff.push_back(0);
			cout<<"Polynomial: 0"<<endl;
		}
		Polynomial(const vector<int> &c) : coeff(c) {
			trim();
		}

		Polynomial operator+(const Polynomial& other){
			vector<int> result(max(coeff.size(), other.coeff.size()));
			for(int i = 0; i < coeff.size() ; ++i){
				result[i] += coeff[i];
			}
			for(int i = 0; i < other.coeff.size() ; ++i){
				result[i] += other.coeff[i];
			}
			return Polynomial(result);
		}

		Polynomial operator-(const Polynomial& other){
			vector<int> result(max(coeff.size(), other.coeff.size()));
			for(int i = 0; i < coeff.size() ; ++i){
				result[i] += coeff[i];
			}
			for(int i = 0; i < other.coeff.size() ; ++i){
				result[i] -= other.coeff[i];
			}
			return Polynomial(result);
		}

		Polynomial operator*(const Polynomial& other){
			vector<int> result(coeff.size() + other.coeff.size() - 1);
			for(int i = 0; i < coeff.size() ; ++i){
				for(int j = 0; j < other.coeff.size() ; ++j){
					result[i + j] += coeff[i] * other.coeff[j];
				}
			}
			return Polynomial(result);
		}
		
		friend ostream& operator<<(ostream& os, const Polynomial& p){
			if(p.coeff.empty()){
				os<<"0";
				return os;
			}
			bool first = true;
			for(int i = p.coeff.size() - 1 ; i >= 0; --i){
				int coefficient = p.coeff[i];

				if(coefficient == 0){
					continue;
				}

				if(!first){
					os<<((coefficient > 0)?" +" : " -");
				} else if(coefficient < 0){
					os<<" -";
				}

				if(abs(coefficient) != 1 || i == 0){
					os<<abs(coefficient);
				}

				if(i > 0){
					os<<"x";
					if(i > 1){
						os<<"^"<<i;
					}
				}

				first = false;
			}
			return os;
		}
		friend class PolynomialUtils;
};

class PolynomialUtils{
	public:
		static int evaluate(const Polynomial& p, int x){
			int result = 0;
			int power = 1;
			for(int coeff : p.coeff){
				result += coeff * power;
				power *= x;
			}
			return result;
		}

		static Polynomial derivative(const Polynomial& p){
			if(p.coeff.size() <= 1){
				return Polynomial();
			}
			vector<int> derivative(p.coeff.size() - 1);
			for(int i = 1; i < p.coeff.size(); ++i){
				derivative[i-1] = p.coeff[i] * i;
			}
			return Polynomial(derivative);
		}
};

int main(int argc, char** argv){
	Polynomial p1({4, 0, 3, 0, 0});   // 3x^2 + 4, added leading zeroes
    Polynomial p2({-1, 3});     // 3x - 1

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;
    Polynomial deriv = PolynomialUtils::derivative(p1);
	int eval = PolynomialUtils::evaluate(p1, 2);

	cout<<"p1: "<<p1<<endl;
	cout<<"p2: "<<p2<<endl;
	cout<<"Sum: "<<sum<<endl;
	cout<<"Diff: "<<diff<<endl;
	cout<<"Product: "<<prod<<endl;
	cout<<"Derivative of p1: "<<deriv<<endl;
	cout<<"Evaluation of p1 at x=2: "<<eval<<endl;

	return 0;
}