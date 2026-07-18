# 🏥 Hospital Patient Management System (C++ OOP)

## 📌 Problem Description

A hospital wants to develop a simple **Patient Management System** to manage different types of patients and calculate their medical bills. The system should demonstrate important **Object-Oriented Programming (OOP)** concepts such as **Abstraction, Inheritance, Runtime Polymorphism, Method Overloading, Exception Handling, and the STL Collection Framework (`unordered_map`)**.

---

# 🎯 Objectives

- Create an abstract `Patient` class.
- Implement different billing systems for indoor and outdoor patients.
- Store patient information using `unordered_map`.
- Search patients using their Patient ID.
- Handle invalid searches using custom exceptions.
- Demonstrate method overloading with admit and discharge operations.

---

# 📋 Requirements

## 1. Abstract Class (`Patient`)

Create an abstract class named `Patient`.

### Attributes

- Patient ID
- Patient Name
- Age

### Functions

- `display_info()`
- `calculate_bill()` (Pure Virtual Function)
- `get_patient_id()`

---

## 2. Inheritance

Create two derived classes.

### Indoor Patient

Additional Attribute

- Number of Days

Billing Policy

```
Bill = Number of Days × 2000
```

---

### Outdoor Patient

Additional Attribute

- Consultation Fee

Billing Policy

```
Bill = Consultation Fee
```

---

## 3. Method Overloading

Implement the following overloaded functions inside the base class.

### Admit Patient

```cpp
admit();
```

Displays

```
Patient Admitted
```

---

### Admit Patient with Room Number

```cpp
admit(int roomNo);
```

Displays

```
Patient Admitted in Room 205
```

---

### Discharge Patient

```cpp
discharge();
```

Displays

```
Patient Discharged
```

---

### Discharge with Date

```cpp
discharge(string date);
```

Displays

```
Patient Discharged on 20-07-2026
```

---

## 4. Collection Framework

Create a `Hospital` class using

```cpp
unordered_map<string, Patient*>
```

Functions should support:

- Add Patient
- Search Patient
- Display All Patients
- Calculate Total Hospital Bill

---

## 5. Exception Handling

Create a custom exception class

```cpp
invalid_name
```

Throw this exception whenever a patient cannot be found.

---

## 6. Main Program

The program should demonstrate:

- Adding Indoor Patients
- Adding Outdoor Patients
- Displaying all patients
- Searching a patient using Patient ID
- Calculating hospital bills
- Demonstrating method overloading
- Demonstrating exception handling

---

# 💻 OOP Concepts Used

- Abstract Class
- Pure Virtual Function
- Inheritance
- Function Overriding
- Runtime Polymorphism
- Method Overloading
- Exception Handling
- STL (`unordered_map`)
- Dynamic Memory Allocation

---

# 🔍 Code Explanation

## 1. Custom Exception

```cpp
class invalid_name : public runtime_error
```

A custom exception class is created by inheriting from `runtime_error`. It is thrown whenever a patient search fails.

---

## 2. Abstract Class (`patient`)

The `patient` class acts as the base class for every patient.

### Data Members

- Patient ID
- Patient Name
- Age

### Functions

### `display_info()`

Displays the common information of every patient.

---

### `calculate_bill()`

```cpp
virtual double calculate_bill() = 0;
```

This is a **Pure Virtual Function**, making `patient` an abstract class. Every derived class must implement its own billing policy.

---

### `get_patient_id()`

Returns the patient's ID. It is used as the key inside the `unordered_map`.

---

### Method Overloading

Four overloaded member functions are implemented.

```cpp
admit();
admit(int roomNo);

discharge();
discharge(string date);
```

These demonstrate **Compile-Time Polymorphism**.

---

## 3. Indoor Patient Class

`indoor_patient` inherits from the `patient` class.

### Additional Data Member

```cpp
int num_of_days;
```

### Bill Calculation

```cpp
Bill = Number of Days × 2000
```

The class overrides

```cpp
calculate_bill()
```

to return the hospital bill.

---

## 4. Outdoor Patient Class

`outdoor_patient` also inherits from `patient`.

### Additional Data Member

```cpp
double consultation_fee;
```

### Bill Calculation

```cpp
Bill = Consultation Fee
```

It overrides the same virtual function to calculate the bill differently.

---

## 5. Hospital Class

The Hospital class stores all patient records using

```cpp
unordered_map<string, patient*> mp;
```

where

- Key → Patient ID
- Value → Pointer to Patient Object

---

### add_patient()

Adds a new patient into the hospital database.

```cpp
mp[p->get_patient_id()] = p;
```

---

### search_patient()

Searches a patient using Patient ID.

If the patient exists,

```cpp
return mp[id];
```

Otherwise,

```cpp
throw invalid_name("Patient Not Found!");
```

---

### display()

Traverses the `unordered_map` and displays all patient information.

```cpp
for(auto x : mp)
```

Runtime polymorphism ensures that the correct `display_info()` function is executed.

---

### calculate_hospital_bill()

Calculates each patient's bill and also computes the total hospital bill.

```cpp
totalBill += patientBill;
```

---

## 6. Main Function

The program demonstrates the complete workflow.

### Step 1

Create Indoor and Outdoor patient objects dynamically.

```cpp
new indoor_patient(...)
new outdoor_patient(...)
```

---

### Step 2

Store them inside the Hospital object.

```cpp
hs.add_patient(...)
```

---

### Step 3

Display all patients.

```cpp
hs.display();
```

---

### Step 4

Demonstrate Method Overloading.

```cpp
admit();
admit(roomNo);

discharge();
discharge(date);
```

---

### Step 5

Calculate bills for every patient.

```cpp
hs.calculate_hospital_bill();
```

---

### Step 6

Search a valid patient.

```cpp
hs.search_patient("101");
```

If found, the patient's details are displayed.

---

### Step 7

Search an invalid patient.

```cpp
hs.search_patient("999");
```

Since the patient does not exist, the program throws a custom exception which is handled using

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
- Constructor Chaining
- Inheritance
- Function Overriding
- Runtime Polymorphism
- Method Overloading
- Exception Handling
- Custom Exception
- `unordered_map`
- Dynamic Memory Allocation
- Object-Oriented Programming (OOP)

---

# ✅ Conclusion

This project demonstrates how Object-Oriented Programming concepts can be used to build a simple Hospital Patient Management System. The program uses abstraction to define a common patient interface, inheritance to support different patient types, runtime polymorphism for bill calculation, method overloading for admission and discharge operations, `unordered_map` for efficient patient management, and custom exception handling to manage invalid patient searches.
