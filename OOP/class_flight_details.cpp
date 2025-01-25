#include <iostream>
#include <string>
using namespace std;

class Airlines {
private:
    string flightNumber;
    string flightName;
    string customerName;
    int seatNumber;
    string source;
    string destination;
    string journeyDate;
    int capacity;

public:

    void readFlightInfo() {
        cout << "Enter flight number: ";
        cin >> flightNumber;
        cout << "Enter flight name: ";
        cin.ignore();
        getline(cin, flightName);
        cout << "Enter customer name: ";
        getline(cin, customerName);
        cout << "Enter seat number: ";
        cin >> seatNumber;
        cout << "Enter source: ";
        cin.ignore();
        getline(cin, source);
        cout << "Enter destination: ";
        getline(cin, destination);
        cout << "Enter journey date (DD/MM/YYYY): ";
        getline(cin, journeyDate);
        cout << "Enter flight capacity: ";
        cin >> capacity;
    }

    void showFlightInfo() const {
        cout << "\nFlight Details:" << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Flight Name: " << flightName << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Seat Number: " << seatNumber << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Journey Date: " << journeyDate << endl;
        cout << "Flight Capacity: " << capacity << endl;
    }
};

int main() {
    Airlines flight;
    flight.readFlightInfo();
    flight.showFlightInfo();
    return 0;
}