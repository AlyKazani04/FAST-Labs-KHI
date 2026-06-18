#include <iostream>
#include <string>
#include <unordered_map>
#include <any>
using namespace std;

class badTypeException : public exception{ // custom exception
    public:
        const char* what() const noexcept override{
            return "BadTypeException : Incorrect Type Requested.";
        }
};

class TypeSafeContainer{ // can store multiple types, just needs key to retrieve
    private:
        unordered_map<int,any> stuff;
    public:
        template <class T>
        void store(int key, const T& val){ // distinct key to add new val, same key to overwrite
            stuff[key] = val;
        }
        template <class T>
        T get(int key) const{ 
            auto item = stuff.find(key);
            if(item == stuff.end()){
                throw out_of_range("Key not found");
            }
            try{
                return any_cast<T>(item->second);
            } catch(const bad_any_cast&){
                throw badTypeException();
            }
        }

        bool checkKeyExists(int key) const{
            return stuff.find(key) != stuff.end();
        }
};

int main(){

    TypeSafeContainer container;
    container.store(1, "Mr.cheese"); // string at 1
    container.store(2, 100); // int at 2
    container.store(2, 1.9006); // float/double at 3

    try{
        string name = container.get<string>(1);
        int age = container.get<int>(2);
        double height_m = container.get<double>(3);

        cout<<"Name: "<<name<<"\nAge: "<<age<<"\nHeight(in meters): "<<height_m<<endl;

        float wrongtype = container.get<float>(1); // throws badTypeException
    }
    catch(const badTypeException& err){
        cerr<<err.what()<<endl;
    } 
    catch(const exception& exc){
        cerr<<"Other Exception caught.\n"<<exc.what()<<endl;
    }

    return 0;
}