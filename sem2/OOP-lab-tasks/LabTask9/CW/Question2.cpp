#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Logger {
	private:
		vector<string> logs;
		const int MAX_LOGS = 100;

		void addLog(const string& severity, const string& module, const string& message) {
			string fullLog = "[" + severity + "] [" + module + "] " + message;
			if (logs.size() >= MAX_LOGS) {
				logs.erase(logs.begin());
			}
			logs.push_back(fullLog);
		}

	public:
		void logInfo(const string& module, const string& message) {
			addLog("INFO", module, message);
		}

		void logWarning(const string& module, const string& message) {
			addLog("WARNING", module, message);
		}

		void logError(const string& module, const string& message) {
			addLog("ERROR", module, message);
		}

		friend class Auditor;
};

class Auditor {
	private:
		string id;
		string password;

		bool authenticate(const string& inputID, const string& inputPass) const {
			return inputID == id && inputPass == password;
		}

	public:
		Auditor(string i, string p) : id(i), password(p) {}

		vector<string> getLogs(const Logger& logger, const string& inputID, const string& inputPass) {
			if (authenticate(inputID, inputPass)) {
				return logger.logs;
			} else {
				cout << "Access Denied: Invalid credentials.\n";
				return {};
			}
		}
};

int main() {
	Logger logger;

	logger.logInfo("Network", "Connected to 192.168.0.1");
	logger.logWarning("Temperature", "Device Temperature higher than usual");
	logger.logError("Security", "Multiple failed login attempts");

	for (int i = 4; i < 101; ++i) {
		logger.logInfo("System", "Log message #" + to_string(i));
	}

	Auditor auditor("admin", "admin");

	vector<string> logs = auditor.getLogs(logger, "admin", "admin");

	cout << "\n___ Retrieved Logs (" << logs.size() << ") ___\n";
	for (auto& log : logs) {
		cout << log << "\n";
	}

	auditor.getLogs(logger, "admin", "wrongpass");

	return 0;
}