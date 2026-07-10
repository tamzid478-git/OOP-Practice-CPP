# 🏦 Bank Management System

A console-based C++ application to manage bank accounts, handle deposits/withdrawals, and calculate interest using Object-Oriented Programming (OOP) concepts.

---

### 📝 Problem Statement
The goal of this project is to implement a robust banking system that supports:
* **Abstract Class (BankAccount):** Defines common attributes (accountNumber, accountHolder, balance) and methods.
* **Method Overloading:** Implements multiple versions of deposit and withdraw methods.
* **Collection Framework:** Uses a HashMap (`std::unordered_map`) to store and search accounts efficiently by account number.
* **Exception Handling:** Implements custom exceptions (`InsufficientFundsException`, `AccountNotFoundException`) for safe error management.
* **Demonstration:** A main program to demonstrate account creation, transactions, and displaying details.

---

### 💻 Code Explanation
This implementation uses several advanced C++ concepts:

1. **Custom Exceptions**: Used `InsufficientFundsException` and `AccountNotFoundException` to handle runtime errors safely using `try-catch` blocks.
2. **Abstract Class**: `BankAccount` acts as an abstract base class with a pure virtual function `calculateInterest()`.
3. **Method Overloading**: Both `deposit()` and `withdraw()` functions are overloaded to handle simple transactions as well as transactions with extra details (source/reason).
4. **Collection Framework**: `unordered_map<string, BankAccount*>` is used in the `Bank` class for efficient O(1) average-time complexity account searching.
5. **Dynamic Memory Allocation**: Objects are managed using pointers in a map to demonstrate polymorphic behavior.

---

### 🚀 Usage
1. Compile the code using: `g++ -o bank_system main.cpp`
2. Run the application: `./bank_system`

---
*Created as part of my C++ OOP Lab Project.*
