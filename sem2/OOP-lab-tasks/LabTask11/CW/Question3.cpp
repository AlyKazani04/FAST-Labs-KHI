#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class arrayIndexOutofBounds : public exception{
    public: 
        const char* what() const noexcept override{
            return "ArrayIndexOutOfBounds : Index not found.";
        }
};

template <class T>
class SafeArray{
    private:
        T* array;
        size_t size;
    public:
        SafeArray(T* a = NULL, size_t s = 0) {
            size = s;
            array = NULL;
            if(s != 0){
                array = new T[size];
                for(int i = 0; i < size; i++){
                    array[i] = a[i];
                }
            }
        }
        T& operator[](int index){
            if(index >= size){
                throw arrayIndexOutofBounds();
            }
            return array[index];
        }

        void print(){
            for(int i = 0; i < size; i++){
                cout<<"Index "<<i<<": "<<array[i]<<endl;
            }
        }
};  

int main(){

    string data[3] = {"hello", "we", "come in peace"};
    SafeArray<string> arr(data, 3);
    cout<<"Array: "<<endl;
    arr.print();

    try{ // accessing data
        cout<<arr[0]<<endl;
        cout<<arr[1]<<endl;
        cout<<arr[2]<<endl;
        //exception
        cout<<arr[3]<<endl;
    }
    catch(arrayIndexOutofBounds& err){
        cerr<<err.what()<<endl;
    }
    catch(const exception& e){
        cout<<"Other Exception: "<<e.what()<<endl;
    }
    return 0;
}