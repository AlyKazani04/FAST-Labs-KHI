#include <iostream>
#include <vector>
using namespace std;


class BigInteger{
    private:
        vector<int> digits;
        bool isNegative;
        void RemoveLeadingZeroes(){
            while(digits.size() > 1 && digits.back() == 0){
                digits.pop_back();
            }
            if( digits.size() == 1 && digits[0] == 0 ){
                isNegative = false;
            }
        }
        static bool absLessThan(const BigInteger& a, const BigInteger& b){
            if(a.digits.size() != b.digits.size()){
                return a.digits.size() < b.digits.size();
            }
            for(int i = a.digits.size() - 1; i >= 0; --i){
                if(a.digits[i] != b.digits[i]){
                    return a.digits[i] < b.digits[i];
                }
            }
            return false;
        }
    public:
        BigInteger() : digits(1,0), isNegative(false){}
        BigInteger(const string& str){
            isNegative = false;
            digits.clear();
            
            int start = 0;
            if(str[0] == '-'){
                isNegative = true;
                start = 1;
            }

            for(int i = str.length() - 1; i >= start; i--){
                digits.push_back(str[i] - '0');
            }
            RemoveLeadingZeroes();
        }

        friend istream& operator>>(istream& in, BigInteger& num){
            string s;
            in>>s;
            num = BigInteger(s);
            return in;
        }
    
        friend ostream& operator<<(ostream& out, const BigInteger& num){
            if(num.isNegative){
                out << "-";
            }
            for(int i = num.digits.size() - 1; i >= 0; --i){
                out << num.digits[i];
            }
            return out;
        }

        BigInteger operator-() const {
            BigInteger result = *this;
            if (!(result.digits.size() == 1 && result.digits[0] == 0)) {
                result.isNegative = !result.isNegative;
            }
            return result;
        }

        
        BigInteger operator+(const BigInteger& other) const{
            if(isNegative == other.isNegative){
                BigInteger result;
                result.isNegative = isNegative;
                
                const int maxlen = max(digits.size(), other.digits.size());
                int carry = 0;
                for(int i = 0; i < maxlen || carry; ++i){
                    int a = (i < digits.size() ? digits[i] : 0);
                    int b = (i < other.digits.size() ? other.digits[i] : 0);
                    int sum = a + b + carry;
                    result.digits.push_back(sum % 10);
                    carry = sum / 10;
                }
                result.RemoveLeadingZeroes();
                return result;
            } else {
                BigInteger result;
                if(isNegative){
                    result = other - ( -(*this));
                } else{
                    result = (*this) - (-other);
                }
                return result;
            }
        }
        
        BigInteger operator-(const BigInteger& other) const{
            if(isNegative != other.isNegative){
                return *this + (-other);
            }
            
            if(absLessThan(*this, other)){
                BigInteger result = other - *this;
                result.isNegative = !isNegative;
                return result;
            }
            
            BigInteger result;
            result.isNegative = isNegative;
            int borrow = 0;
            
            for( int i = 0; i < digits.size(); ++i ){
                int a = digits[i];
                int b = (i < other.digits.size() ? other.digits[i] : 0);
                int diff = a - b - borrow;
                
                if(diff < 0){
                    diff += 10;
                    borrow = 1;
                } else{
                    borrow = 0;
                }
                result.digits.push_back(diff);
            }
            
            result.RemoveLeadingZeroes();
            return result;
        }

        bool operator==(const BigInteger&  other) const{
            return isNegative == other.isNegative && digits == other.digits;
        }
        
        bool operator!=(const BigInteger& other) const{
            return !(*this == other);
        }
    
        bool operator<(const BigInteger& other) const{
            if(isNegative != other.isNegative){
                return isNegative;
            }
            
            bool absoluteCompare = absLessThan(*this, other);
            return isNegative ? !absoluteCompare && *this != other : absoluteCompare;
        }
        
        bool operator>(const BigInteger& other) const{
            return other < *this;
        }
        
        bool operator<=(const BigInteger& other) const{
            return !(other < *this );
        }
        bool operator>=(const BigInteger& other) const{
            return !(*this < other );
        }
        
    };
    
    
    
int main(){
    BigInteger a, b;
    cout<<"Enter two big integers: ";
    cin>>a>>b;
    
    cout<<"Sum:        "<<a + b<<endl;
    cout<<"Difference: "<<a - b<<endl;
    cout<<"Equal:      "<<(a == b ? "Yes" : "No")<<endl;
    cout<<"Less than:  "<<(a < b ? "Yes" : "No")<<endl;
    
    return 0;
}