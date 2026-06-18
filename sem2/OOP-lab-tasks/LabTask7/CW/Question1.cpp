#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Fraction{
	private:
		int nume;
		int denom;
	public:
		Fraction(){};
		Fraction(float x, float y) : nume(x), denom(y) {
			float g = gcd(nume, denom);
			nume /= g;
			denom/= g;
			cout<<"Fraction: "<<nume<<" / "<<denom<<endl;
		}
		Fraction operator+(const Fraction& other){
			int temp_nume = nume * other.denom + other.nume* denom;
			int temp_denom = denom * other.denom;
			Fraction temp(temp_nume, temp_denom);
			return temp;
		}
		Fraction operator-(const Fraction& other){
			int temp_nume = nume * other.denom - other.nume* denom;
			int temp_denom = denom * other.denom;
			Fraction temp(temp_nume, temp_denom);
			return temp;
		}
		Fraction operator*(const Fraction& other){
			int temp_nume = nume * other.nume;
			int temp_denom = denom * other.denom;
			Fraction temp(temp_nume, temp_denom);
			return temp;
		}
		Fraction operator/(const Fraction& other){
			int temp_nume = nume * other.denom;
			int temp_denom = denom * other.nume;
			Fraction temp(temp_nume, temp_denom);
			return temp;
		}
		bool operator==(const Fraction& other){
			if(nume == other.nume && denom == other.denom){
				return true;
			}
			return false;
		}
		bool operator!=(const Fraction& other){
			if(nume == other.nume && denom == other.denom){
				return false;
			}
			return true;
		}
		bool operator<(const Fraction& other){
			if(nume/denom < other.nume/other.denom){
				return true;
			}
			return false;	
		}
		bool operator>(const Fraction& other){
			if(nume/denom > other.nume/other.denom){
				return true;
			}
			return false;
		}
		bool operator<=(const Fraction& other){
			if(nume/denom <= other.nume/other.denom){
				return true;
			}
			return false;
		}
		bool operator>=(const Fraction& other){
			if(nume/denom >= other.nume/other.denom){
				return true;
			}
			return false;
		}
		friend std::ostream& operator<<(std::ostream& out, const Fraction& f){
			if(f.denom == 1){
				out<<f.nume;
			} else{
				out<<f.nume<<"/"<<f.denom;
			}
			return out;
		}
		friend std::istream& operator>>(std::istream& in, Fraction& f){
			int numerator, denominator;
			char slash;
			in>>numerator>>slash>>denominator;
			if(!in || slash != '/'){
				throw invalid_argument("Invalid input");
			} else{
				f = Fraction(numerator, denominator);
			}
			return in;
		}
	};

int main(int argc, char** argv){
	Fraction f1(8,12);
	Fraction f2(5,6);

	bool d = f2 < f1;
	
	cout<<"f1 + f2 = "<<(f1 + f2)<<endl; // Outputs: 3/2 = 5/6 + 2/3

    Fraction f3;
    cout<<"Enter a fraction (e.g. 3/4): ";
    cin>>f3;
    cout<<"You entered: "<<f3<<endl;
	
	return 0;
}