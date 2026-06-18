#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int lcount = 0;
	int fcount = 1;
	ofstream logFile("Log1.txt");

	if (!logFile.is_open()) {
		cout << "Failed to create file!" << endl;
		return 1;
	}

	string line;
	cout << "Enter lines (type END to stop):" << endl;

	while (true) {
		getline(cin, line);

		if (line == "END") {
			break;
		}

		logFile << line << endl;
		lcount++;

        if (lcount == 10) {
			logFile.close();
			fcount++;
			lcount = 0;

			string fileName = "Log" + to_string(fcount) + ".txt";
			logFile.open(fileName);

			if (!logFile.is_open()) {
				cerr << "Failed to create " << fileName << endl;
				return 1;
			}
		}
	}

	logFile.close();
	cout << "Input saved. " << fcount << " file(s) created." << endl;

	return 0;
}