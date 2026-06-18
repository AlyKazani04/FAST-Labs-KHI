#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class Employee{
    public:
        int id;
        string name;
        string designation;
        int years;
};

class Application{
    private:
        string filename = "Database.txt";
    public:
        Application(const string& file) : filename(file){}
        void addPerson(const Employee& emp){
            ofstream file(filename);
            file<<emp.id<<","<<emp.name<<","<<emp.designation<<","<<emp.years<<"\n";
            file.close();
        }
        vector<Employee> getAllEmployees(){
            vector<Employee> employees;
            ifstream file(filename);
            string line;
            
            while(getline(file,line)){
                stringstream ss(line);
                Employee emp;
                string tempid;
                string tempyears;
                getline(ss , tempid, ',');
                emp.id = stoi(tempid);
                getline(ss, emp.name, ',');
                getline(ss, emp.designation, ',');
                getline(ss, tempyears, '\n');
                emp.years = stoi(tempyears);

                employees.push_back(emp);
            }
            return employees;
        }

        void writeAllEmployeestoFile(const vector<Employee>& employees){
            ofstream file(filename);
            for(const auto& emp : employees){
                file<<emp.id<<","<<emp.name<<","<<emp.designation<<","<<emp.years<<"\n";
            }
            file.close();
        }

        vector<Employee> findManagersGreaterthan2Years(){
            vector<Employee> result;
            auto employees = getAllEmployees();

            for(const auto& emp : employees){
                if(emp.designation == "manager" && emp.years >= 2){
                    result.push_back(emp);
                }
            }
            return result;
        }

        void overwritewithManagers(){
            auto managers = findManagersGreaterthan2Years();
            writeAllEmployeestoFile(managers);
        }
        
        void IncrementManagers(){
            auto managers = findManagersGreaterthan2Years();
            for(auto& emp : managers){
                emp.id += 100;
                emp.years += 1;
            }
            writeAllEmployeestoFile(managers);
        }

        void displayAll(const vector<Employee>& employees){
            for(auto& emp : employees){
                cout<<emp.id<<" "<<emp.name<<" "<<emp.designation<<" "<<emp.years<<endl;
                
            }
        }
};

int main(){
    Application manager("Employees.txt");

    // write dummy data
    std::ofstream file("Employees.txt");
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }
    file<<"1,Aly,manager,3\n";
    file<<"2,Marley,engineer,2\n";
    file<<"3,Ayaan,manager,1\n";
    file<<"4,Klein,technician,4\n";
    file<<"5,FangYuan,manager,2\n";
    file.close();

    cout<<"Current Employees: "<<endl;
    manager.displayAll( manager.getAllEmployees());
    cout<<endl;

    cout<<"Managers with 2 or more years of service: "<<endl;
    auto filter = manager.findManagersGreaterthan2Years();
    manager.displayAll(filter);
    cout<<endl;

    cout<<"Overwrite File with result from first query: "<<endl;
    manager.overwritewithManagers();
    manager.displayAll(manager.getAllEmployees());
    cout<<endl;

    cout<<"Rewrite with incremented managers: "<<endl;
    manager.IncrementManagers();
    manager.displayAll(manager.getAllEmployees());
    cout<<endl;

    return 0;
}