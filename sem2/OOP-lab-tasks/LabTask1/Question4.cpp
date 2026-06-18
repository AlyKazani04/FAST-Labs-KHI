#include <bits/stdc++.h>
using namespace std;

float KilotoPounds(float weight){
	return weight * 2.2;
}

int main(int argc, char* argv[]){
	float weight;
	cout<<"Enter Weight in Kilograms: ";
	cin>>weight;
	cout<<"\nWeight in Kilos: "<<fixed<<setprecision(2)<<weight<<endl;
	cout<<"Weight in Pounds: "<<fixed<<setprecision(2)<<KilotoPounds(weight)<<endl;
	return 0;
}

