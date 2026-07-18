# 📚 Smart Library Management System (C++ OOP Project)

## Overview

This project is a simple **Smart Library Management System** developed in **C++** using **Object-Oriented Programming (OOP)** concepts.

The program manages different types of library items such as **Books** and **Magazines**, stores them dynamically using the **STL vector**, allows searching by title, and calculates overdue fines.

---

# Problem Statement

Design a **Smart Library Management System** using C++.

The system should contain a base class named **LibraryItem** and two derived classes:

- Book
- Magazine

The system should also use **Method Overloading**, **Inheritance**, **Polymorphism**, and **STL**.

---

# Requirements

## 1. Base Class : LibraryItem

Create a base class named **LibraryItem** having the following attributes:

- Item ID
- Title
- Published Year

### Constructor

Create a parameterized constructor to initialize all data members.

### Functions

- `displayInfo()` → Displays all item information.
- `calculateFine(int daysLate)` → Returns overdue fine.

Since different items have different fine policies, this function is declared as a **Pure Virtual Function**, making `LibraryItem` an **Abstract Class**.

---

## 2. Derived Classes

### Book

Additional Attribute

- Author

Fine Policy

- **2 taka per overdue day**

Override

- `displayInfo()`
- `calculateFine()`

---

### Magazine

Additional Attribute

- Issue Number

Fine Policy

- **1 taka per overdue day**

Override

- `displayInfo()`
- `calculateFine()`

---

## 3. Method Overloading

Create a class named **Library**.

Overload the function:

```cpp
addItem(Book)
addItem(Magazine)
```

Both functions insert library items into an STL container.

---

## 4. STL Usage

Use

```cpp
vector<LibraryItem*>
```

to store all library items dynamically.

The system should support

- Add Books
- Add Magazines
- Display all items
- Search by title
- Calculate total overdue fine

---

# Functional Requirements

The user should be able to

1. Add multiple books.
2. Add multiple magazines.
3. Display all library items.
4. Search an item by title.
5. Input overdue days.
6. Calculate total library fine.

---

# Sample Input

```
Number of Items : 2

Book
ID : 101
Title : OOP
Year : 2023
Author : C++

Magazine
ID : 201
Title : TechMonthly
Year : 2024
Issue Number : 5

Search Title
OOP

Days Late
Book : 5
Magazine : 3
```

---

# Expected Output

```
Book Found

Fine : 10 taka

Magazine Fine : 3 taka

Total Fine : 13 taka
```

---

# OOP Concepts Used

- Classes & Objects
- Encapsulation
- Inheritance
- Abstract Class
- Pure Virtual Function
- Function Overriding
- Runtime Polymorphism
- Method Overloading
- Dynamic Memory Allocation

---

# STL Concepts Used

- vector
- Dynamic Storage
- Range-based for loop

---

# Code Explanation

## 1. LibraryItem (Base Class)

```cpp
class LibraryItem
```

This is the abstract base class.

### Data Members

- itemID
- title
- year

### Functions

### displayInfo()

Displays common information of every library item.

### calculateFine()

```cpp
virtual int calculateFine(int daysLate)=0;
```

This is a **Pure Virtual Function**.

Therefore,

- LibraryItem becomes an **Abstract Class**.
- Objects of LibraryItem cannot be created directly.
- Every derived class must implement this function.

---

## 2. Book Class

```cpp
class Book : public LibraryItem
```

Additional member

```cpp
author
```

Fine Policy

```
Fine = Days Late × 2
```

Overrides

- displayInfo()
- calculateFine()

---

## 3. Magazine Class

```cpp
class Magazine : public LibraryItem
```

Additional member

```cpp
issueNumber
```

Fine Policy

```
Fine = Days Late × 1
```

Overrides

- displayInfo()
- calculateFine()

---

## 4. Library Class

The Library class manages all library items.

### STL Container

```cpp
vector<LibraryItem*> v;
```

A vector of base-class pointers stores both Book and Magazine objects.

This demonstrates **Runtime Polymorphism**.

---

## 5. Method Overloading

```cpp
addItem(Book)
```

Adds a Book object.

```cpp
addItem(Magazine)
```

Adds a Magazine object.

Same function name,
Different parameter types.

This is **Compile-time Polymorphism (Method Overloading).**

---

## 6. Display Function

```cpp
displayAll()
```

Traverses the vector and calls

```cpp
displayInfo()
```

Since it is virtual, the correct derived class function is executed automatically.

---

## 7. Search Function

```cpp
searchByTitle()
```

Compares the given title with every stored item.

If found,

- Displays complete information.

Otherwise,

```
Item Not Found
```

---

## 8. Fine Calculation

```cpp
calculateTotalFine()
```

For every item,

- User enters overdue days.
- Calls

```cpp
calculateFine()
```

using polymorphism.

Adds every item's fine to produce the total library fine.

---

# Formula

## Book

```
Fine = Days Late × 2
```

## Magazine

```
Fine = Days Late × 1
```

---

# Learning Outcomes

After completing this project, you will understand

- Abstract Classes
- Pure Virtual Functions
- Function Overriding
- Runtime Polymorphism
- Method Overloading
- Dynamic Object Creation
- STL Vector
- Searching Algorithms
- Designing a Real-world OOP Project

---

# Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL (Vector)
- Dynamic Memory Allocation
- GCC / G++
