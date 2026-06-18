#include <bits/stdc++.h>
using namespace std;

class Glass{
	public:
		int LiquidLevel;
		Glass(){
			LiquidLevel = 200;
			cout<<"Initial: "<<LiquidLevel<<endl;
		}
		void Drink(int ml){
			if(ml < 0){
				cout<<"No negatives please."<<endl;
				return;
			}
			if(LiquidLevel >= ml){
				LiquidLevel -= ml;
				cout<<"Level after drinking: "<<LiquidLevel<<endl;
			}
		}
		void Refill(){
			LiquidLevel += (200 - LiquidLevel);
			cout<<"Refilled: "<<LiquidLevel<<endl;
		}
};

int main(int argc, char** argv){
	int num, amount_drank;
	Glass glass_of_water;
	while(1){
		cout<<"Glass of Water:"<<endl;
		cout<<"\tEnter 1 to drink water"<<endl;
		cout<<"\tEnter 0 to stop drinking."<<endl;
		cout<<"Enter: ";
		cin>>num;
		switch(num){
			case 1:
				cout<<"Enter Amount to be drunk: ";
				cin>>amount_drank;
				glass_of_water.Drink(amount_drank);
				if(glass_of_water.LiquidLevel < 100){
					glass_of_water.Refill();
				}
				break;
			case 0:
				cout<<"Stopped Drinking."<<endl;
				return 0;
			default:
				cout<<"\tHuh? You're not supposed to have found this."<<endl;
				cout<<"\tYou prolly entered ml u wanted to drink instead of 1 or 0."<<endl;
				cout<<"\tTry Again.\n\tBye"<<endl;
				return 0;
		}
	}
	return 0;
}
