#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        virtual float getTuition(const string& status, int creditHours) const = 0;
};

class GraduateStudent : public Student {
    private:
        string researchTopic;

    public:
        GraduateStudent(const string& topic = "") : researchTopic(topic) {}

        string getResearchTopic() const {
            return researchTopic;
        }
        void setResearchTopic(const string& topic) {
            researchTopic = topic;
        }
        float getTuition(const string& status, int creditHours) const override {
            if (status == "undergraduate") {
                return 10000.0 * creditHours;
            } else if (status == "graduate") {
                return 9500.0 * creditHours;
            } else if (status == "doctoral") {
                return 8500.0 * creditHours;
            } else {
                cerr << "Unknown student status: " << status << endl;
                return 0.0;
            }
        }
};

int main() {
    GraduateStudent grad;
    grad.setResearchTopic("Artificial Intelligence");

    cout << "Research Topic: " << grad.getResearchTopic() << endl;

    string status = "graduate";
    int creditHours = 12;

    float tuition = grad.getTuition(status, creditHours);
    cout << "Tuition for a " << status << " student taking " << creditHours << " credit hours: Rs." << tuition << endl;

    return 0;
}
