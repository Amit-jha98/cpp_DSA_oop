#include <iostream>
#include <string>
#include <regex>
#include <limits>
#include <algorithm>
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

    // Validate non-empty string with max length
    bool isValidInput(const string& str) {
        return !str.empty() && str.length() <= 50;
    }

    // Validate alphanumeric flight number
    bool isValidFlightNumber(const string& str) {
        return regex_match(str, regex("^[a-zA-Z0-9]+$"));
    }

    // Validate date format (DD/MM/YYYY)
    bool isValidDate(const string& date) {
        regex dateRegex("^([0-2][0-9]|(3)[0-1])/(0[1-9]|1[0-2])/\\d{4}$");
        return regex_match(date, dateRegex);
    }

    // Sanitize input to remove leading/trailing spaces
    string sanitizeInput(string input) {
        input.erase(0, input.find_first_not_of(" \t\n\r"));
        input.erase(input.find_last_not_of(" \t\n\r") + 1);
        return input;
    }

    // Clear input buffer
    void clearBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    Airlines() : seatNumber(0), capacity(0) {}

    // Read flight and passenger details
    bool readFlightInfo() {
        try {
            cout << "\n=== Enter Flight Details ===\n";
            
            // Flight number
            do {
                cout << "Flight number (alphanumeric): ";
                cin >> flightNumber;
                flightNumber = sanitizeInput(flightNumber);
                if (!isValidFlightNumber(flightNumber)) {
                    cout << "Invalid flight number! Use alphanumeric characters only.\n";
                }
            } while (!isValidFlightNumber(flightNumber));

            clearBuffer();
            
            // Flight name
            do {
                cout << "Flight name: ";
                getline(cin, flightName);
                flightName = sanitizeInput(flightName);
                if (!isValidInput(flightName)) {
                    cout << "Invalid flight name! Maximum length is 50 characters.\n";
                }
            } while (!isValidInput(flightName));

            cout << "\n=== Enter Passenger Details ===\n";

            // Customer name
            do {
                cout << "Customer name: ";
                getline(cin, customerName);
                customerName = sanitizeInput(customerName);
                if (!isValidInput(customerName)) {
                    cout << "Invalid customer name! Maximum length is 50 characters.\n";
                }
            } while (!isValidInput(customerName));

            // Seat number
            do {
                cout << "Seat number (1-100): ";
                cin >> seatNumber;
                if (cin.fail() || seatNumber < 1 || seatNumber > 100) {
                    cout << "Invalid seat number! Enter a value between 1 and 100.\n";
                    clearBuffer();
                    seatNumber = 0;
                }
            } while (seatNumber == 0);

            clearBuffer();

            cout << "\n=== Enter Journey Details ===\n";

            // Source
            do {
                cout << "Source: ";
                getline(cin, source);
                source = sanitizeInput(source);
                if (!isValidInput(source)) {
                    cout << "Invalid source! Maximum length is 50 characters.\n";
                }
            } while (!isValidInput(source));

            // Destination
            do {
                cout << "Destination: ";
                getline(cin, destination);
                destination = sanitizeInput(destination);
                if (!isValidInput(destination) || destination == source) {
                    cout << "Invalid destination! It must not be the same as the source and maximum length is 50 characters.\n";
                }
            } while (!isValidInput(destination) || destination == source);

            // Journey date
            do {
                cout << "Journey date (DD/MM/YYYY): ";
                getline(cin, journeyDate);
                if (!isValidDate(journeyDate)) {
                    cout << "Invalid date format! Use DD/MM/YYYY.\n";
                }
            } while (!isValidDate(journeyDate));

            // Flight capacity
            do {
                cout << "Flight capacity (10-500): ";
                cin >> capacity;
                if (cin.fail() || capacity < 10 || capacity > 500) {
                    cout << "Invalid capacity! Enter a value between 10 and 500.\n";
                    clearBuffer();
                    capacity = 0;
                }
            } while (capacity == 0);

            return true;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            return false;
        }
    }

    // Display flight details
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
        cout << "===========================\n";
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
