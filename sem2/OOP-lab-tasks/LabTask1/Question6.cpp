#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){
	string line, name = "", number, values = "";
	float total = 0;
	int index = 0, count;
	getline(cin, line);
	while(index < line.size() && !(line[index] >= '0' && line[index] <= '9') && line[index] != '-' && line[index] != '.'){
	name += line[index];
	index++;
	}
	count = index;
	while(count < line.size()){
	values += line[count];
	count++;
	}
	while(!name.empty() && (name[name.size() - 1] == ' ')){
	name.resize(name.size() - 1);
	}
	for(int i = 0; i < 5 ; i++){
		number = "";
		int numlength = 0;
		while(index < line.size() && line.at(index) != ' ' && line.at(index) != '\n' && line.at(index) != '\0'){
			number += line[index];
			index++;
			numlength++;
		}
		index++;
		if(!number.empty())
			total += atof(number.c_str());
	}
	float average = total/5;
	cout<<"Student Name: "<<name<<endl;
	cout<<"Test Scores: "<<values<<endl;
	cout<<"Average: "<<fixed<<setprecision(2)<<average<<endl;
	return 0;
}
