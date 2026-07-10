#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept> 

using namespace std;

class FlightNotFoundException : public runtime_error {
public:
    FlightNotFoundException(const string& msg) : runtime_error(msg) {}
};

class Flight {
protected:
    string flightNumber;
    string source;
    string destination;

public:
    Flight(string flightNumber, string source, string destination) {
        this->flightNumber = flightNumber;
        this->source = source;
        this->destination = destination;
    }

    // Abstract method (Pure Virtual Function)
    virtual double getTicketPrice() = 0;

    virtual void displayDetails() {
        cout << "Flight: " << flightNumber << " | Route: " << source << " -> " << destination;
    }

    string getFlightNumber() {
        return flightNumber;
    }

    virtual ~Flight() {}
};


class EconomyFlight : public Flight {
private:
    double basePrice;

public:
    EconomyFlight(string flightNumber, string source, string destination, double basePrice) 
        : Flight(flightNumber, source, destination)
        {
            this->basePrice=basePrice;
        }

    double getTicketPrice() override 
    {
        return basePrice;
    }

    void displayDetails() override {
        Flight::displayDetails();
        cout << " | Class: Economy  | Ticket Price: $" << getTicketPrice() << endl;
    }
};

class BusinessFlight : public Flight {
private:
    double basePrice;

public:
    BusinessFlight(string fNum, string src, string dest, double price) 
        : Flight(fNum, src, dest), basePrice(price) {}

    double getTicketPrice() override {
        return basePrice * 1.5;
    }

    void displayDetails() override {
        Flight::displayDetails();
        cout << " | Class: Business | Ticket Price: $" << getTicketPrice() << endl;
    }
};


// 4. Collection Framework (FlightManager)

class FlightManager {
private:
    unordered_map<string, Flight*> mp; // Using HashMap style matching

public:
    void addFlight(Flight* p) {
        mp[p->getFlightNumber()] = p;
        cout << "Flight " << p->getFlightNumber() << " registered successfully." << endl;
    }

    Flight* searchFlight(string Num) {
        if (mp.find(Num) == mp.end()) {
            throw FlightNotFoundException("Error: Flight '" + Num + "' not p in the system!");
        }
        return mp[Num];
    }

    void displayAllFlights() {
        cout << "\n--- All Available Flights ---" << endl;
        for (auto x : mp) {
            x.second->displayDetails();
        }
    }
};


int main() {
    FlightManager manager;

    // ১. বিভিন্ন ধরনের ফ্লাইট তৈরি এবং যুক্ত করা
    cout << "=== Registering Flights ===" << endl;
    manager.addFlight(new EconomyFlight("BG-021", "Dhaka", "Chittagong", 4000.0));
    manager.addFlight(new BusinessFlight("EK-582", "Dhaka", "Dubai", 50000.0));
    manager.addFlight(new EconomyFlight("QR-640", "Dhaka", "Doha", 35000.0));

  
    manager.displayAllFlights();

    
    cout << "\n--- Searching & Booking Available Flight ---" << endl;
    try {
        string searchNum = "EK-582";
        Flight* p = manager.searchFlight(searchNum);
        cout << "Success! Flight Found for Booking:" << endl;
        p->displayDetails();
    } 
    catch (const FlightNotFoundException& e) {
        cout << e.what() << endl;
    }

    
    cout << "\n--- Testing Exception Handling (Invalid Flight) ---" << endl;
    try {
        string invalidNum = "BG-999";
        Flight* p = manager.searchFlight(invalidNum);
    } 
    catch (const FlightNotFoundException& e) {
        
        cout << e.what() << endl;
    }

    return 0;
}
