# 🚌 University Transport Management System (C++ OOP Project)

## Overview

This project is a simple **University Transport Management System** developed using **C++** and **Object-Oriented Programming (OOP)** concepts.

The system manages different types of university vehicles such as **Bus** and **Car**, stores them dynamically using the **STL vector**, allows searching vehicles by driver name, and calculates passenger fares.

---

# Problem Statement

Design a **University Transport Management System** using C++.

The system should contain a base class named **Vehicles** and two derived classes:

- Bus
- Car

The project demonstrates the use of inheritance, constructor inheritance, runtime polymorphism, abstract classes, and STL.

---

# Requirements

## 1. Base Class : Vehicles

Create a base class named **Vehicles** with the following attributes:

- Vehicle ID
- Driver Name
- Capacity

### Constructor

Create a parameterized constructor to initialize all data members.

### Member Functions

- `displayinfo()` → Displays vehicle information.
- `fare_calculation(int passengers)` → Calculates fare.

Since fare policies are different for Bus and Car, this function is declared as a **Pure Virtual Function**.

---

## 2. Derived Classes

### Bus

Additional Attribute

- Route Number

Fare Policy

```
50 taka per passenger
```

Override

- displayinfo()
- fare_calculation()

---

### Car

Additional Attribute

- Car Type

Fare Policy

```
100 taka per passenger
```

Override

- displayinfo()
- fare_calculation()

---

## 3. STL Usage

Use

```cpp
vector<Vehicles*>
```

to store all vehicles dynamically.

The system supports

- Adding buses
- Adding cars
- Displaying all vehicles
- Searching vehicles by driver name
- Calculating passenger fare

---

# Functional Requirements

The user should be able to

1. Add multiple buses and cars.
2. Display all vehicle information.
3. Search vehicles using driver name.
4. Enter passenger numbers.
5. Calculate fare for every vehicle.

---

# Sample Input

```
Number of Vehicles : 2

Choice : 1

Bus ID : 101
Driver : Rahim
Capacity : 40
Route : 5

Choice : 2

Car ID : 201
Driver : Karim
Capacity : 4
Company : Micro

Search Driver
Rahim

Passengers

Bus : 30
Car : 3
```

---

# Expected Output

```
Details of Bus

Bus Fare : 1500

Details of Car

Car Fare : 300
```

---

# OOP Concepts Used

- Classes & Objects
- Encapsulation
- Inheritance
- Abstract Class
- Pure Virtual Function
- Constructor Inheritance
- Function Overriding
- Runtime Polymorphism
- Dynamic Memory Allocation

---

# STL Concepts Used

- vector
- Dynamic Object Storage
- Range-based for loop

---

# Code Explanation

## 1. Vehicles Class (Base Class)

```cpp
class vehicles
```

This is the abstract base class of the project.

### Data Members

- vehicle_id
- driver_name
- capacity

### Constructor

```cpp
vehicles(int vehicle_id,string driver_name,int capacity)
```

Initializes all common vehicle information.

---

### displayinfo()

Displays common information of every vehicle.

---

### fare_calculation()

```cpp
virtual void fare_calculation(int passenger)=0;
```

This is a **Pure Virtual Function**.

Therefore,

- Vehicles becomes an **Abstract Class**.
- Objects of Vehicles cannot be created.
- Every derived class must implement this function.

---

# 2. Bus Class

```cpp
class bus : public vehicles
```

Derived from Vehicles.

### Additional Data Member

```
route_number
```

### Constructor

Uses the base class constructor to initialize inherited members.

```cpp
bus(...): vehicles(...)
```

### displayinfo()

Displays complete bus information.

### fare_calculation()

```
Bus Fare = Passenger × 50
```

---

# 3. Car Class

```cpp
class car : public vehicles
```

Derived from Vehicles.

### Additional Data Member

```
car_type
```

### Constructor

Uses the base class constructor.

```cpp
car(...): vehicles(...)
```

### displayinfo()

Displays complete car information.

### fare_calculation()

```
Car Fare = Passenger × 100
```

---

# 4. STL Container

The program stores all vehicles inside

```cpp
vector<vehicles*>
```

Using pointers allows storing both Bus and Car objects inside the same vector.

This is an example of **Runtime Polymorphism**.

---

# 5. Adding Vehicles

The user selects

```
1 → Bus

2 → Car
```

According to the choice, a new object is created dynamically using

```cpp
new bus(...)
```

or

```cpp
new car(...)
```

and stored in the vector.

---

# 6. Display All Vehicles

The program traverses the vector

```cpp
for(auto x : v)
```

and calls

```cpp
x->displayinfo();
```

Because the function is virtual, the correct derived class function is executed automatically.

---

# 7. Search Vehicle

The user enters a driver's name.

The program compares

```cpp
x->driver_name
```

with the searched name.

If matched,

```
displayinfo()
```

is called to display that vehicle.

---

# 8. Fare Calculation

For every stored vehicle,

The user enters passenger count.

The program calls

```cpp
x->fare_calculation(passenger);
```

The correct fare function is selected automatically through runtime polymorphism.

---

# Fare Formula

## Bus

```
Fare = Passenger × 50
```

## Car

```
Fare = Passenger × 100
```

---

# Learning Outcomes

After completing this project, you will understand

- Constructor Inheritance
- Abstract Classes
- Pure Virtual Functions
- Function Overriding
- Runtime Polymorphism
- Dynamic Memory Allocation
- STL Vector
- Searching Objects
- Designing a Real-world OOP Project

---

# Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL (Vector)
- Dynamic Memory Allocation
- GCC / G++
