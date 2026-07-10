# ✈️ Air Flight Management System

A console-based C++ application designed to manage flight records, ticket pricing, and bookings using Object-Oriented Programming (OOP) concepts.

---

### 📝 Problem Statement
The goal of this system is to manage available flights and ticket bookings by implementing the following requirements:

* **Abstract Class (Flight):** Defined a base class `Flight` with attributes: `flightNumber`, `source`, and `destination`, along with an abstract method `getTicketPrice()`.
* **Inheritance:** Implemented two subclasses:
    * `EconomyFlight`: Returns the base price.
    * `BusinessFlight`: Returns 1.5 times the base price.
* **Collection Framework:** Utilized `std::unordered_map` as a HashMap in the `FlightManager` class to store flights using `flightNumber` as the key.
* **Exception Handling:** Defined a custom exception class `FlightNotFoundException` to handle cases where a user searches for a non-existent flight.
* **Demonstration:** A main program that adds flights, displays all available flights, handles bookings, and demonstrates exception handling.

---

### 💻 Code Explanation

This project demonstrates core OOP principles effectively:

1. **Abstraction & Polymorphism**: The `Flight` class acts as an interface/abstract class. Using `virtual` functions ensures that `getTicketPrice()` and `displayDetails()` are implemented specifically for `EconomyFlight` and `BusinessFlight` classes.
2. **Inheritance**: The system uses inheritance to extend the `Flight` class, allowing code reusability for different flight categories.
3. **Data Management**: By using `unordered_map<string, Flight*>`, we achieve efficient $O(1)$ average time complexity for searching flights by their unique `flightNumber`.
4. **Error Handling**: Custom exceptions provide a safe way to manage runtime errors, specifically when a flight search fails, preventing the application from crashing.

---

### 🚀 Usage
1. Compile the code:
   ```bash
   g++ main.cpp -o flight_system
