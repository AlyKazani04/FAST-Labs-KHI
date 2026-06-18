#include <iostream>
using namespace std;

struct Incident
{
    int severity, timestamp; // timestamp = 24hr clock, e.g: 0700 = 7 AM
    string description;

    Incident() =default;

    Incident(int sev, int t, string desc) : severity(sev), timestamp(t), description(desc) {}
};

class DispatchSystem
{
    private:
        Incident incidents[100];
        int size;

        int parent(int i){ return (i - 1) / 2; }
        int left(int i){ return 2 * i + 1; }
        int right(int i){ return 2 * i + 2; }

        void heapify_up(int index)
        {
            while(index != 0 && incidents[index].severity >= incidents[parent(index)].severity)
            {
                if(incidents[index].severity == incidents[parent(index)].severity)
                {
                    if(incidents[index].timestamp < incidents[parent(index)].timestamp)
                    {
                        break;
                    }
                }
                swap(incidents[index], incidents[parent(index)]);
                index = parent(index);
            }
        }
        
        void heapify_down(int index)
        {
            int largest = index; 
            int l = left(index);
            int r = right(index);

            if(l < size && incidents[l].severity > incidents[largest].severity)
            {
                largest = l;
            }
            if(r < size && incidents[r].severity > incidents[largest].severity)
            {
                largest = r;
            }

            if(largest != index)
            {
                swap(incidents[index], incidents[largest]);
                heapify_down(largest);
            }
        }

    public:
        DispatchSystem(){ size = 0; }

        void add(Incident inc) 
        {
            if(size == 100) 
            {
                cout << "Incident List Full!\n";
                return;
            }

            incidents[size] = inc;
            heapify_up(size);
            size++;      
        }
        
        void dispatch()
        {
            if (size == 0)
            {
                cout << "NO INCIDENTS!\n";
                return;
            }

            incidents[0] = incidents[size - 1];
            size--;

            heapify_down(0);

            cout << "Dispatched!\nNext incident: " << endl;
            cout << "Severity (Scale 1-10): " << nextIncident().severity << endl;
            cout << "Timestamp: " << nextIncident().timestamp << endl;
            cout << "Description: " << nextIncident().description << endl << endl;
        }

        Incident nextIncident() const
        {
            return incidents[0];
        }

        void display()
        {
            cout << "Incidents: " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << "Severity (Scale 1-10): " << incidents[i].severity << endl;
                cout << "Timestamp: " << incidents[i].timestamp << endl;
                cout << "Description: " << incidents[i].description << endl << endl;
            }
        }
};

int main()
{
    DispatchSystem system;

    system.add({ 5, 1100, "Car Crash" });

    system.add({ 7, 300, "Bank Robbery" });

    system.add({ 3, 1500, "Lost Child" });

    system.add({ 5, 900, "Car Crash" });

    system.display();

    system.dispatch();

    system.display();

    return 0;    
}