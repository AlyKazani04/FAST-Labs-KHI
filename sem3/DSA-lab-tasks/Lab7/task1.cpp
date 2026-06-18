#include <iostream>
using namespace std;

struct destination
{
    string name;
    int eta;

    destination(int e, string n) : eta(e), name(n) {}
};

class DeliveryLogistics
{
    private:
        destination* arr;
        int size;
    public:
        DeliveryLogistics(destination* list, int s) : arr(list), size(s) {}
        ~DeliveryLogistics() =default;

        void quickSort(int low, int high)
        {
            if(low < high)
            {
                int pi = partition(arr, low, high);

                quickSort(low, pi - 1);
                quickSort(pi + 1, high);
            }
        }

        void printDeliveries()
        {
            for(int i = 0; i < size; i++)
            {
                cout << "Deliveries: " << endl;
                cout << (arr + i)->name << " | ETA: " << (arr + i)->eta << endl;
            }
        }
    private:
        int partition(destination* list, int low, int high)
        {
            destination pivot = list[high];
            int i = low - 1;

            for(int j = low; j < high; j++)
            {
                if(list[j].eta < pivot.eta)
                {
                    i++;
                    destination temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
                if(list[j].eta == pivot.eta)
                {
                    if(list[j].name[list[j].name.size() - 1] < pivot.name[pivot.name.size() - 1])
                    {
                        i++;
                        destination temp = list[i];
                        list[i] = list[j];
                        list[j] = temp;
                    }
                }
            }

            destination temp = arr[i + 1];
            arr[i + 1] = arr[high];
            arr[high] = temp;

            return i + 1;
        }
};

int main()
{
    destination destinations[] = 
    {
        { 120, "Customer B" },
        {  90, "Customer A" },
        {  45, "Customer C" },
        { 120, "Customer D" }
    }; 

    DeliveryLogistics system(destinations, 4);

    system.quickSort(0, 3);

    system.printDeliveries();

    return 0;
}