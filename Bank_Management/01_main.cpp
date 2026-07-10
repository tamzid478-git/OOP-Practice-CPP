#include <iostream>
#include <string>
#include <unordered_map> // HashMap এর জন্য
#include <stdexcept> 

using namespace std;

// --- Custom Exceptions ---
class InsufficientFundsException : public runtime_error {
public:
    InsufficientFundsException(const string& msg) : runtime_error(msg) {}
};

class AccountNotFoundException : public runtime_error {
public:
    AccountNotFoundException(const string& msg) : runtime_error(msg) {}
};

// --- Abstract Class (BankAccount) ---
class BankAccount {
protected:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(string accountNumber, string accountHolder, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolder = accountHolder;
        this->balance = balance;
    }

    // Abstract method (Pure Virtual Function)
    virtual void calculateInterest() = 0;

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
    }

    void deposit(double amount, string source) {
        balance += amount;
        cout << "Deposited: " << amount << " from " << source << ". New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException("Error: You tried to withdraw " + to_string(amount) + " but your balance is only " + to_string(balance));
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
    }

    void withdraw(double amount, string reason) {
        if (amount > balance) {
            throw InsufficientFundsException("Error: Cannot withdraw " + to_string(amount) + " for " + reason + ". Insufficient balance!");
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << " for " << reason << ". New Balance: " << balance << endl;
    }

    
    virtual void displayAccountDetails() {
        cout << "Account No: " << accountNumber << ", Holder: " << accountHolder << ", Balance: " << balance << endl;
    }
    
    string getAccountNumber() {
        return accountNumber;
    }
};

// Derived Class (SavingsAccount) 
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string accHolder, double bal, double rate) 
        : BankAccount(accNum, accHolder, bal) {
        interestRate = rate;
    }

    // Abstract method implementation
    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        cout << "Calculated Interest: " << interest << endl;
    }
};

// Collection Framework (Bank Class with HashMap) 
class Bank 
{
private:
    unordered_map<string, BankAccount*> mp; 

public:
    // Adding new account
    void addAccount(BankAccount* p) {
        mp[p->getAccountNumber()] = p;
        cout << "Account added successfully." << endl;
    }

    // serching account by account number
    BankAccount* searchAccount(string accNum) {
        if (mp.find(accNum) != mp.end()) {
            return mp[accNum];
        }
       
        throw AccountNotFoundException("Error: Account not found!"); 
    }

    void displayAllmp() {
        cout << "--- All mp ---" << endl;
        for (auto x : mp) {
            x.second->displayAccountDetails();
        }
    }
};


int main() {
    Bank myBank;

    // creating new account
    SavingsAccount* ptr = new SavingsAccount("101", "Rahim", 5000.0, 5.0);
    myBank.addAccount(ptr);

    cout << "\n--- Testing Deposits ---" << endl;
   
    ptr->deposit(1000); 
    ptr->deposit(2000, "Salary"); 

    cout << "\n--- Testing Withdrawals & Exceptions ---" << endl;
    try {
       
        ptr->withdraw(500); 
        ptr->withdraw(1500, "Rent"); 
        ptr->withdraw(20000); 
    } 
    catch (const InsufficientFundsException& e) {
        cout << e.what() << endl; 
    }

    cout << "\n--- Testing Account Search Exception ---" << endl;
    try {
      
        BankAccount* foundAcc = myBank.searchAccount("999");
    } 
    catch (const AccountNotFoundException& e) {
        cout << e.what() << endl;
    }

    cout << "\n--- Display Final Account Details ---" << endl;
    
    myBank.displayAllmp();
    ptr->calculateInterest();

    return 0;
}
