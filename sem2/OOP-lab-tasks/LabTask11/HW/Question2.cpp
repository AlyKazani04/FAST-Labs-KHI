#include <iostream>
#include <exception>
using namespace std;

class StackUnderFlowException : public exception{ // custom exception
    public:
        const char* what() const noexcept override{
            return "StackUnderFlowException : No item to Pop or No item to View.";
        }
};

template <class T>
class Stack{
    private:
        T elements[100];
        int topIndex;
    public:
        Stack() : topIndex(-1) {}

        void push(T arg){
            if(topIndex == 99){
                cout<<"Stack Full."<<endl;
                return;
            }
            topIndex++;
            elements[topIndex] = arg;
        }

        T pop(){
            if(topIndex == -1){
                throw StackUnderFlowException();
            }
            cout<<"Popped: "<<elements[topIndex]<<endl;
            return elements[topIndex--];
        }

        T top(){
            if(topIndex == -1){
                throw StackUnderFlowException();
            }
            cout<<"Stack Top: "<<elements[topIndex]<<endl;
            return elements[topIndex];
        }
};

int main(){

    Stack<string> stack;
    stack.push("Message");  // 1
    stack.push("Will");     // 2
    stack.push("Come");     // 3
    stack.push("Out");      // 4
    stack.push("Reversed"); // 5

    try{
        stack.pop(); // 1
        stack.pop(); // 2
        stack.pop(); // 3
        stack.pop(); // 4
        stack.top(); // out: Message
        stack.pop(); // 5
        stack.pop(); // exception
        
    }
    catch(StackUnderFlowException& err){
        cout<<err.what()<<endl;
    }

    return 0;
}