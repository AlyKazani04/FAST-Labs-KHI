#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Doctor;
class Billing;

class PatientRecord{
    private:
        string name;
        int id;
        string date_of_birth;

        vector<string> history;
        string current_treatment;
        vector<string> billing_records;
    public:
        PatientRecord(string n, int i, string d) :
            name(n), id(i), date_of_birth(d) {}

        string getPublicData() const{
            return "Patient: " + name + " ID: " + to_string(id) + " DOB: " + date_of_birth;
        }
    private:
        string getMedicalData(){
            string data = "Medical History:\n";
            for (const auto& item : history) {
                data += " -" + item + "\n";
                data += "Current Treatment: " + current_treatment + "\n";
            }
            return data;
        }
        void updateMedicalHistory(const string& data){
            history.push_back(data);
        }
        void updateCurrentTreatment(const string& treatment){
            current_treatment = treatment;
        }
        void addBillingDetails(const string& detail){
            billing_records.push_back(detail);
        }
        void showBilling() const{
            cout<<"Billing Info: \n";
            for (const auto& item : billing_records) {
                cout<<" -"<<item<<endl;
            }
        }
        friend class Doctor;
        friend class Billing;
};

class Doctor{
    public:
        void Diagnose(PatientRecord& record, const string& diagnosis){
            record.updateMedicalHistory("Diagnosed with: " + diagnosis);
        }
        void Prescribe(PatientRecord& record, const string& treatment){
            record.updateCurrentTreatment(treatment);
        }
        void viewMedicalInfo(PatientRecord& patient){
            cout<<patient.getMedicalData();
        }
};

class Billing{
    public:
        void addBill(PatientRecord& patient, const string& bill){
            patient.addBillingDetails(bill);
        }
        void showBill(const PatientRecord& patient){
            patient.showBilling();
        }
};

class Receptionist{
    public:
        void greetPatient(const PatientRecord& patient){
            cout<<"Welcome to our clinic!"<<endl;
            cout<<"Here's your public info: "<<endl;
            cout<<patient.getPublicData()<<endl;
        }
};

int main(int argc, char**argv){
    
    PatientRecord p("John", 101, "11-09-2001");

    Doctor doc;
    doc.Diagnose(p, "Flu");
    doc.Prescribe(p, "Rest and fluids");

    Billing biller;
    biller.addBill(p, "Checkup - $100");

    Receptionist r;
    r.greetPatient(p);

    cout<<"\nDoctor View:\n";
    doc.viewMedicalInfo(p);

    cout<<"\nBilling View:\n";
    biller.showBill(p);

	return 0;
}