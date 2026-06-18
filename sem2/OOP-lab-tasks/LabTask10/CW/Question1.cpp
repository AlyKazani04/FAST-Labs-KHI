#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Handler{
    private:
        string filename = "Encrypt.txt";
        fstream file;
        string Encrypt(string in){
            int size = in.size();
            for(int i = 0; i < size; i++){
                in[i] = (char)((int)in[i] + i+1);
            }
            return in; 
        }
        string Decrypt(string line){
            int size = line.size();
            for(int i = 0; i < size;i++){
                line[i] = (char)((int)line[i] - i-1);
            }
            return line;
        }
    public:
        Handler(){}
        void readFile(){
            file.open(filename, ios::in);
            if(!file.is_open()){
                cerr<<"File Opening Error!"<<endl;
                exit(1);
            }
            string line;
            getline(file, line);
            line = Decrypt(line);
            cout<<line<<endl;
            file.close();
        }
        void insertFile(string line){
            file.open(filename,ios::out);
            if(!file.is_open()){
                cerr<<"File Not Found!"<<endl;
                exit(1);
            }
            line = Encrypt(line);
            file<<line;
            cout<<"Encrypted line: "<<line<<endl;
            file.close();
        }
        ~Handler(){
            file.close();
        }
};

int main(){
    Handler filehandle;
    filehandle.insertFile("Hello World");
    filehandle.readFile();

    return 0;
}