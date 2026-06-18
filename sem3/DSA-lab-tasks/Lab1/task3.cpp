#include <iostream>
using namespace std;

class Box
{
    private:
        int* value;
    public:
        void subtract(int val)
        {   
            *value -= val;
            cout << "Subtracted " << val << endl;
            BoxValue();
        }

        int BoxValue()
        {
            cout << "Value: " << *value << endl;
            return *value;
        }

        Box(int val)
        {
            value = new int(val);

            BoxValue();
        }

        Box(const Box& other)
        {
            value = new int(*other.value);
            cout << "Copy Constructor Called" << endl;
            BoxValue();
        }
        
        Box& operator=(const Box& other)
        {
            if(this != &other)
            {
                delete value;
                value = new int(*other.value);

                cout << "Assignment Operator Called" << endl;
                BoxValue();
            }

            return *this;
        }

        Box shallowCopy()
        {
            Box temp(0);
            delete temp.value; 

            temp.value = this->value; // copying pointer directly
            cout << "Shallow Copy Called" << endl;

            return temp;
        }

        ~Box()
        {
            delete value;
            cout << "Destructor called" << endl;
        }
};

int main()
{
    Box box1(10);

    cout << "Deep Copy: " << endl;

    Box box2 = box1;

    box2.subtract(2);

    cout << "Box 2 ";
    box2.BoxValue();
    
    cout << "Box 1 ";
    box1.BoxValue();

    cout << "Shallow Copy: " << endl;

    Box box3 = box1.shallowCopy();
    cout << "Box 3 ";
    box3.BoxValue();

    box3.subtract(5);

    cout << "Box 3 ";
    box3.BoxValue();

    cout << "Box 1 ";
    cout << box1.BoxValue() << endl;

    
    return 0;
}