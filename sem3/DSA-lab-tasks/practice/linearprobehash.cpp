#include <iostream>
using namespace std;

struct Cell
{
    int val = 0, key = 0;
    bool empty = true;

    Cell() =default;
};

const int MAXSIZE = 100;

class LinearHash
{
    private:
        Cell table[MAXSIZE];

        int hash(int key)
        {
            return key % MAXSIZE;
        }

    public:
        void insert(int key, int val)
        {
            int index = hash(key);
            while(table[index].empty == false)
            {
                index = (index + 1) % MAXSIZE;
            }

            table[index].val = val;
            table[index].key = key;
            table[index].empty = false;
        }

        void remove(int key)
        {
            int index = hash(key);
            while(table[index].key != key)
            {
                index = (index + 1) % MAXSIZE;
            }

            table[index].empty = true;
        }

        int find(int key)
        {
            int index = hash(key);
            int end = (index - 1) % MAXSIZE;
            while(table[index].key != key && index != end)
            {
                index = (index + 1) % MAXSIZE;
            }
            if(table[index].key != key)
            {
                return -1;
            }
            else
            {
                return table[index].val;
            }
        }
};

int main()
{
    LinearHash hash;

    hash.insert(274, 153);
    hash.insert(222, 3);
    hash.insert(224, 12);
    hash.insert(223, 121);

    cout << hash.find(223) << endl;
    cout << hash.find(212) << endl;

    return 0;
}