#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Passenger;

class Flight{
    private:
        struct BookingInfo{
            int passengerID;
            string seatclass;
        };

        string flightNumber;
        string Departure;
        string Arrival;
        int capacity;
        int bookedSeats;

        vector<BookingInfo> bookings;
        int findBookingIndex(const int passengerID) const{
            for (int i = 0; i < bookings.size(); i++) {
                if (bookings[i].passengerID == passengerID) {
                    return i;
                }
            }
            return -1;
        }
    public:
        Flight(string fn, string d, string a, int c) :
            flightNumber(fn), Departure(d), Arrival(a), capacity(c), bookedSeats(0) {}

        bool bookSeat(const int passengerID, const string seatclass) {
            if(bookedSeats >= capacity) {
                cout<<"Flight is full.\n";
                return false;
            }
            if(findBookingIndex(passengerID) != -1) {
                cout<<"Passenger already booked.\n";
                return false;
            }
            bookings.push_back({passengerID, seatclass});
            bookedSeats++;
            cout<<"Seat Booked for: "<<passengerID<<" in "<<seatclass<<endl;
            return true;
        }

        bool cancelBooking(const int passengerID) {
            if(bookedSeats == 0){
                cout<<"Flight is empty.\n";
                return false;
            }
            int index = findBookingIndex(passengerID);
            if(index == -1) {
                cout<<"Passenger not found.\n";
                return false;
            }
            bookings.erase(bookings.begin() + index);
            bookedSeats--;
            cout<<"Booking cancelled for: "<<passengerID<<endl;
            return true;
        }

        bool upgradeSeat(const int passengerID, const string& newSeatClass) {
            if(bookedSeats == 0) {
                cout<<"Flight is empty.\n";
                return false;
            }
            int index = findBookingIndex(passengerID);
            if(index == -1) {
                cout<<"Passenger not found.\n";
                return false;
            }
            bookings[index].seatclass = newSeatClass;
            cout<<"Seat upgraded for: "<<passengerID<<" to "<<newSeatClass<<endl;
            return true;
        }
        void showStatus() const{
            cout<<"Flight "<<flightNumber<<": "<<bookedSeats<<" / "<<capacity<<" seats booked.\n";
            
        }

        friend class Passenger;
};

class Passenger{
    private:
        int id;
        string name;
    public:
        Passenger(int i, string n) : id(i), name(n) {}
        void requestBooking(Flight& flight, const string& seatClass);
        void cancelBooking(Flight& flight);
        void requestUpgrade(Flight& flight, const string& newSeatClass);
};

void Passenger::requestBooking(Flight& flight, const string& seatClass){
    flight.bookSeat(id, seatClass);
}

void Passenger::cancelBooking(Flight& flight){
    flight.cancelBooking(id);
}

void Passenger::requestUpgrade(Flight& flight, const string& newSeatClass){
    flight.upgradeSeat(id, newSeatClass);
}

int main(){

    Flight flight("A123", "KHI", "TKY", 2); // flight number, departure, arrival, capacity = 2 seats

    Passenger Aly(1, "Aly");
    Passenger Bingus(2, "Bingus");
    Passenger Uni(3, "Uni");

    Aly.requestBooking(flight, "Economy");
    Bingus.requestBooking(flight, "Business");
    Uni.requestBooking(flight, "First"); 

    flight.showStatus();

    Bingus.requestUpgrade(flight, "First");

    Aly.cancelBooking(flight);
    Uni.requestBooking(flight, "Economy"); 

    flight.showStatus();    

    return 0;
}
