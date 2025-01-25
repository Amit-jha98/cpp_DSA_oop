#include <iostream>
#include <string>
#include <limits> 
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

    string sanitizeInput(string input) {
        input.erase(0, input.find_first_not_of(" \t\n\r"));
        input.erase(input.find_last_not_of(" \t\n\r") + 1);
        return input;
    }

    void clearBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    Airlines() : seatNumber(0), capacity(0) {}

    bool readFlightInfo() {
        cout << "\n=== Enter Flight Details ===\n";

        cout << "Flight number: ";
        cin >> flightNumber;
        flightNumber = sanitizeInput(flightNumber);

        clearBuffer();

        cout << "Flight name: ";
        getline(cin, flightName);
        flightName = sanitizeInput(flightName);

        cout << "\n=== Enter Passenger Details ===\n";

        cout << "Customer name: ";
        getline(cin, customerName);
        customerName = sanitizeInput(customerName);

        do {
            cout << "Seat number (1-100): ";
            cin >> seatNumber;
            if (cin.fail() || seatNumber < 1 || seatNumber > 100) {
                cout << "Invalid seat number! Please enter a number between 1 and 100.\n";
                clearBuffer();
                seatNumber = 0;
            }
        } while (seatNumber == 0);

        clearBuffer();

        cout << "\n=== Enter Journey Details ===\n";

        cout << "Source: ";
        getline(cin, source);
        source = sanitizeInput(source);

        do {
            cout << "Destination: ";
            getline(cin, destination);
            destination = sanitizeInput(destination);
            if (destination == source) {
                cout << "Destination cannot be the same as source! Please enter again.\n";
            }
        } while (destination == source);

        cout << "Journey date (DD/MM/YYYY): ";
        getline(cin, journeyDate);
        journeyDate = sanitizeInput(journeyDate);

        do {
            cout << "Flight capacity (10-500): ";
            cin >> capacity;
            if (cin.fail() || capacity < 10 || capacity > 500) {
                cout << "Invalid capacity! Please enter a number between 10 and 500.\n";
                clearBuffer();
                capacity = 0;
            }
        } while (capacity == 0);

        return true;
    }

    void showFlightInfo() const {
        cout << "\n====== Flight Details ======\n";
        cout << "Flight Number : " << flightNumber << endl;
        cout << "Flight Name   : " << flightName << endl;
        cout << "Customer Name : " << customerName << endl;
        cout << "Seat Number   : " << seatNumber << endl;
        cout << "Source        : " << source << endl;
        cout << "Destination   : " << destination << endl;
        cout << "Journey Date  : " << journeyDate << endl;
        cout << "Capacity      : " << capacity << " passengers" << endl;
        cout << "=========================\n";
    }
};

int main() {
    Airlines flight;
    cout << "Welcome to Airline Booking System\n";

    if (flight.readFlightInfo()) {
        flight.showFlightInfo();
    } else {
        cout << "Booking failed due to invalid input.\n";
    }

    return 0;
}
