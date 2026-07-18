# ✈️ Air Flight Management System (C++ OOP)

## 📌 Problem Description

An airline company wants to develop a simple **Air Flight Management System** to manage available flights, ticket prices, and bookings. The system demonstrates important **Object-Oriented Programming (OOP)** concepts including **Abstraction, Inheritance, Polymorphism, Exception Handling, and the STL Collection Framework**.

---

# 🎯 Objectives

- Create an abstract `Flight` class.
- Implement different ticket pricing using inheritance.
- Store flights dynamically using `unordered_map` (HashMap).
- Search flights using flight number.
- Handle invalid searches with custom exceptions.

---

# 📋 Requirements

## 1. Abstract Class (`Flight`)

Create an abstract class named `Flight` containing:

### Attributes
- `flightNumber`
- `source`
- `destination`

### Methods
- `getTicketPrice()` → Pure virtual function.
- `displayDetails()` → Displays flight information.
- `getFlightNumber()` → Returns the flight number.

---

## 2. Inheritance

Create two derived classes:

### EconomyFlight
- Stores the base ticket price.
- Returns the base price as the ticket price.

### BusinessFlight
- Stores the base ticket price.
- Returns **1.5 × Base Price** as the ticket price.

---

## 3. Collection Framework

Create a `FlightManager` class using

```cpp
unordered_map<string, Flight*>
```

where the **flight number** is the key.

Functions should support:

- Add new flights
- Search flight by flight number
- Display all available flights

---

## 4. Exception Handling

Create a custom exception class

```cpp
FlightNotFoundException
```

Throw this exception whenever the searched flight does not exist.

---

## 5. Main Program

The program should demonstrate:

- Registering economy and business flights.
- Displaying all available flights.
- Searching and booking a valid flight.
- Searching for an invalid flight and handling the exception.

---

# 💻 OOP Concepts Used

- Abstract Class
- Pure Virtual Function
- Inheritance
- Function Overriding
- Runtime Polymorphism
- Exception Handling
- STL (`unordered_map`)
- Dynamic Memory Allocation

---

# 🔍 Code Explanation

## 1. Custom Exception

```cpp
class FlightNotFoundException : public runtime_error
```

A custom exception derived from `runtime_error` is created. It is thrown when a flight number cannot be found.

---

## 2. Abstract Class (`Flight`)

The `Flight` class acts as the base class.

### Data Members

- Flight Number
- Source
- Destination

### Functions

### `getTicketPrice()`

```cpp
virtual double getTicketPrice() = 0;
```

A pure virtual function that forces every derived class to implement its own ticket pricing.

### `displayDetails()`

Displays the common information of every flight.

### `getFlightNumber()`

Returns the flight number so it can be used as the key inside the `unordered_map`.

---

## 3. Derived Class (`EconomyFlight`)

This class inherits from `Flight`.

Additional member:

```cpp
double basePrice;
```

### Ticket Price

```cpp
return basePrice;
```

The ticket price is simply the base price.

---

## 4. Derived Class (`BusinessFlight`)

Also inherits from `Flight`.

Additional member:

```cpp
double basePrice;
```

### Ticket Price

```cpp
return basePrice * 1.5;
```

Business class passengers pay **150%** of the base ticket price.

---

## 5. FlightManager Class

Stores all flights using

```cpp
unordered_map<string, Flight*> mp;
```

where

- Key → Flight Number
- Value → Pointer to Flight object

### addFlight()

Adds a flight into the collection.

```cpp
mp[p->getFlightNumber()] = p;
```

---

### searchFlight()

Searches a flight using its number.

If the flight exists,

```cpp
return mp[Num];
```

Otherwise,

```cpp
throw FlightNotFoundException(...);
```

---

### displayAllFlights()

Traverses the map and displays every registered flight.

```cpp
for(auto x : mp)
```

---

## 6. Main Function

The program demonstrates the complete workflow.

### Step 1

Create different flights.

```cpp
EconomyFlight
BusinessFlight
```

---

### Step 2

Add them into the `FlightManager`.

```cpp
manager.addFlight(...)
```

---

### Step 3

Display all available flights.

```cpp
manager.displayAllFlights();
```

---

### Step 4

Search and book an existing flight.

```cpp
manager.searchFlight("EK-582");
```

If found, its details are displayed.

---

### Step 5

Search a non-existing flight.

```cpp
manager.searchFlight("BG-999");
```

Since it does not exist, the program throws

```cpp
FlightNotFoundException
```

which is handled using

```cpp
try
{
    ...
}
catch(...)
{
    ...
}
```

---

# 📚 Concepts Demonstrated

- Abstract Class
- Pure Virtual Function
- Inheritance
- Constructor Chaining
- Function Overriding
- Runtime Polymorphism
- Custom Exception
- Exception Handling (`try-catch`)
- `unordered_map` (HashMap)
- Dynamic Memory Allocation (`new`)
- STL Containers

---

# ✅ Conclusion

This project demonstrates how object-oriented programming concepts can be combined to build a simple airline flight management system. Flights are managed dynamically using `unordered_map`, different ticket prices are calculated through inheritance and polymorphism, and invalid flight searches are safely handled using custom exceptions.
