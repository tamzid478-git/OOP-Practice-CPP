# 🏦 Simple Banking System (C++ OOP Project)

## Overview

This project is a **Simple Banking System** developed using **C++** and **Object-Oriented Programming (OOP)** concepts.

The system manages bank accounts, supports deposits and withdrawals using **Method Overloading**, stores accounts using **STL HashMap (unordered_map)**, calculates account interest through **Runtime Polymorphism**, and handles invalid operations using **Custom Exceptions**.

---

# Problem Statement

Design a **Simple Banking System** using C++.

The system should include:

- An Abstract Class named `BankAccount`
- Method Overloading
- Collection Framework (HashMap)
- Exception Handling

---

# Requirements

## 1. Abstract Class : BankAccount

Create an abstract class named **BankAccount** containing the following attributes:

- Account Number
- Account Holder
- Balance

### Constructor

Create a parameterized constructor to initialize all data members.

### Member Functions

- `deposit(double amount)`
- `deposit(double amount, string source)`
- `withdraw(double amount)`
- `withdraw(double amount, string reason)`
- `displayAccountDetails()`

Declare

```cpp
calculateInterest()
```

as a **Pure Virtual Function** so that every account type implements its own interest calculation.

---

## 2. Method Overloading

Overload the following methods:

### Deposit

```cpp
deposit(double amount)
```

Deposit money normally.

```cpp
deposit(double amount, string source)
```

Deposit money with a source (Salary, Gift, Bonus, etc.).

---

### Withdraw

```cpp
withdraw(double amount)
```

Withdraw money normally.

```cpp
withdraw(double amount, string reason)
```

Withdraw money with a reason (ATM, Rent, Online Payment, etc.).

---

## 3. Collection Framework

Create a class named **Bank**.

Store all accounts using

```cpp
unordered_map<string, BankAccount*>
```

where

- Key → Account Number
- Value → Pointer to BankAccount

The Bank class should support

- Add Account
- Search Account
- Display All Accounts

---

## 4. Exception Handling

Create two custom exceptions.

### InsufficientFundsException

Thrown when a withdrawal amount exceeds the available balance.

### AccountNotFoundException

Thrown when an account number does not exist.

---

## 5. Main Program

The program should demonstrate

- Creating a bank account
- Depositing money using overloaded methods
- Withdrawing money
- Exception handling
- Searching accounts
- Displaying account details
- Calculating interest

---

# Sample Output

```
Account added successfully.

Deposited: 1000
Deposited: 2000 from Salary

Withdrawn: 500
Withdrawn: 1500 for Rent

Error:
Insufficient balance

Error:
Account not found

Account Details

Calculated Interest
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
- Exception Handling
- Dynamic Memory Allocation

---

# STL Concepts Used

- unordered_map (HashMap)
- String
- Exception Library

---

# Code Explanation

## 1. Custom Exceptions

Two custom exception classes are created.

### InsufficientFundsException

```cpp
class InsufficientFundsException : public runtime_error
```

This exception is thrown whenever the user tries to withdraw more money than the available balance.

---

### AccountNotFoundException

```cpp
class AccountNotFoundException : public runtime_error
```

This exception is thrown when an invalid account number is searched.

---

# 2. BankAccount Class (Abstract Class)

```cpp
class BankAccount
```

This is the base abstract class.

### Data Members

- accountNumber
- accountHolder
- balance

---

### Constructor

Initializes all common account information.

```cpp
BankAccount(accountNumber, accountHolder, balance)
```

---

### Pure Virtual Function

```cpp
virtual void calculateInterest() = 0;
```

Since different account types may have different interest policies, the function is declared as **Pure Virtual**.

Therefore,

- BankAccount becomes an **Abstract Class**
- Objects of BankAccount cannot be created directly
- Every derived class must implement `calculateInterest()`

---

### Deposit (Method Overloading)

Version 1

```cpp
deposit(double amount)
```

Deposits money normally.

Version 2

```cpp
deposit(double amount, string source)
```

Deposits money with a transaction source.

Example

```
Salary
Gift
Bonus
```

---

### Withdraw (Method Overloading)

Version 1

```cpp
withdraw(double amount)
```

Withdraws money normally.

Version 2

```cpp
withdraw(double amount, string reason)
```

Withdraws money with a transaction purpose.

Example

```
ATM
Rent
Online Transfer
```

If the requested amount exceeds the available balance, an exception is thrown.

---

### displayAccountDetails()

Displays

- Account Number
- Account Holder
- Current Balance

---

# 3. SavingsAccount Class

```cpp
class SavingsAccount : public BankAccount
```

Derived from BankAccount.

### Additional Data Member

```cpp
interestRate
```

Stores the interest percentage.

---

### calculateInterest()

Overrides the pure virtual function.

Formula

```
Interest = Balance × Interest Rate / 100
```

This demonstrates **Runtime Polymorphism**.

---

# 4. Bank Class

```cpp
class Bank
```

This class manages all bank accounts.

---

### STL Container

```cpp
unordered_map<string, BankAccount*> mp;
```

Stores

```
Key   → Account Number

Value → Pointer to BankAccount
```

HashMap provides fast searching based on account number.

---

### addAccount()

Adds a new account into the HashMap.

---

### searchAccount()

Searches an account using its account number.

If found,

Returns the account pointer.

Otherwise,

Throws

```
AccountNotFoundException
```

---

### displayAllAccounts()

Traverses the HashMap and displays every account's information.

---

# 5. Main Function

The program demonstrates the complete banking workflow.

### Step 1

Create a SavingsAccount.

---

### Step 2

Add the account to the Bank.

---

### Step 3

Deposit money using both overloaded methods.

---

### Step 4

Withdraw money.

If balance is insufficient,

```
InsufficientFundsException
```

is thrown.

---

### Step 5

Search an account.

Searching an invalid account number throws

```
AccountNotFoundException
```

---

### Step 6

Display all account information.

---

### Step 7

Calculate account interest.

---

# Exception Flow

## Withdraw

```
Withdraw Amount

↓

Amount > Balance ?

↓

Yes

↓

Throw InsufficientFundsException
```

---

## Search

```
Search Account Number

↓

Found ?

↓

No

↓

Throw AccountNotFoundException
```

---

# Learning Outcomes

After completing this project, you will understand

- Abstract Classes
- Pure Virtual Functions
- Inheritance
- Function Overriding
- Runtime Polymorphism
- Method Overloading
- Custom Exception Handling
- HashMap (unordered_map)
- Dynamic Memory Allocation
- Designing a Real-world Banking System

---

# Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL (`unordered_map`)
- Exception Handling
- GCC / G++
