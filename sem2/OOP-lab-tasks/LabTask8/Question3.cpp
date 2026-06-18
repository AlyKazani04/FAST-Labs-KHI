#include <iostream>
#include <string>
using namespace std;

class Currency{
    protected: 
        float amount;
        string currencyCode;
        string currencySymbol;
        static float exchangeRates[3];
    public:
        Currency(float amt, string code, string csymbol) :
            amount(amt), currencyCode(code), currencySymbol(csymbol) {}
        virtual float convertToBase(){}
        virtual void displayCurrency(){}

        float convertTo(int index){
            if (index >= 0 && index < 3) {
                return convertToBase() * exchangeRates[index];
            }
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        static int getIndex(string code){
            if(code == "USD")
                return 0;
            if(code == "EUR")
                return 1;
            if(code == "PKR")
                return 2;
            return -1;  
        }
        static void setExchangeRate(int index, float rate){
            if(index >= 0 && index < 3){
                exchangeRates[index] = rate;
            }
        }

};

float Currency::exchangeRates[3] = {1.0, 1.1, 0.0036};

class Dollar : public Currency{
    public:
        Dollar(float amt) : Currency(amt, "USD", "$") {}
        float convertToBase() override{
            return amount; // USD is base
        }
        void displayCurrency() override{
            cout<<currencySymbol<<amount<<" "<<currencyCode<<endl;
        }
};

class Euro : public Currency{
    public:
        Euro(float amt): Currency(amt, "EUR", "€") {}
        float convertToBase() override{
            return amount * exchangeRates[1];
        }
        void displayCurrency() override{
            cout<<currencySymbol<<amount<<" "<<currencyCode<<endl;
        }
};

class Rupee : public Currency{
    public:
        Rupee(float amt) : Currency(amt, "PKR", "Rs") {}
        float convertToBase() override{
            return amount * exchangeRates[2];
        }
        void displayCurrency() override{
            cout<<currencySymbol<<amount<<" "<<currencyCode<<endl;
        }
};

int main(){
    Currency::setExchangeRate(0, 1.0);  // Base currency (USD)
    Currency::setExchangeRate(1, 1.1);  // 1 EUR = 1.1 USD
    Currency::setExchangeRate(2, 0.0036); // 1 PKR = 0.0036 USD

    Dollar d(100);
    Euro e(50);
    Rupee r(5000);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout<<"50 EUR to USD: "<<e.convertToBase()<<endl;
    cout<<"5000 PKR to USD: "<<r.convertTo(0)<<endl;
    cout<<"100 USD to EUR: "<<d.convertTo(1)<<endl;
    
    return 0;
}