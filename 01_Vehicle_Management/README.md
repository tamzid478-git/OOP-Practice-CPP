# University Transport Management System

## Overview

This project is a simple **Object-Oriented Programming (OOP)** based University Transport Management System implemented in **C++**. It demonstrates the use of:

- Classes and Objects
- Inheritance
- Constructor Inheritance
- Function Overriding (if implemented)
- STL (`vector`)
- Searching and Fare Calculation

---

# Problem Statement

Design a University Transport Management System that manages different types of university vehicles.

The system should support a base class named **Vehicle** and two derived classes:

- Bus
- Car

The program should store all vehicles using STL and provide searching and fare calculation features.

---

# Requirements

## 1. Base Class: `Vehicle`

Create a base class named `Vehicle` containing the following data members:

- `vehicleID`
- `driverName`
- `capacity`

### Constructor

Create a parameterized constructor to initialize all data members.

### Member Functions

Implement the following functions:

- `displayInfo()` → Displays vehicle information.
- `calculateFare(int passengers)` → Calculates the total fare.

---

## 2. Derived Classes

### Bus

Additional Data Member:

- `routeNumber`

Fare Policy:

- **50** taka per passenger

Requirements:

- Use the base class constructor to initialize inherited data members.

---

### Car

Additional Data Member:

- `carType`

Fare Policy:

- **100** taka per passenger

Requirements:

- Use the base class constructor to initialize inherited data members.

---

## 3. STL Usage

Use an STL container (such as `vector`) to store all vehicles.

The program should support:

- Adding buses and cars
- Displaying all vehicle information
- Calculating fare
- Searching vehicles by driver name

---

## 4. Functional Requirements

The application should allow the user to:

1. Add multiple buses and cars.
2. Display all vehicle information.
3. Search vehicles by driver name.
4. Input the number of passengers.
5. Calculate and display the total fare for each vehicle.

---

# Sample Input

```
Bus:
101
Rahim
40
5

Car:
201
Karim
4
Micro

Passengers:
Bus = 30
Car = 3
```

---

# Expected Output

```
Bus Fare : 1500
Car Fare : 300
```

---

# Concepts Used

- Object-Oriented Programming (OOP)
- Encapsulation
- Inheritance
- Constructor Inheritance
- Parameterized Constructor
- STL Vector
- Searching
- Function Design
- Fare Calculation

---

# Formula

For Bus

```
Fare = Passengers × 50
```

For Car

```
Fare = Passengers × 100
```

---

# Learning Outcome

After completing this project, you will understand:

- How inheritance works in C++
- How derived classes reuse constructors
- How STL containers store objects
- How to search objects by attribute
- How to design a simple real-world management system using OOP
