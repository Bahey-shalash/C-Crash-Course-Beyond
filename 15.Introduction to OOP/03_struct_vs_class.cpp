/*
======================================
  COURSE 3: ENCAPSULATION & DATA HIDING
======================================

📌 **What is Encapsulation?**
   - Encapsulation means **bundling data and behavior into a single unit (class)**.
   - It ensures that **data is not directly accessible** from outside the class.
   - Instead, data is accessed and modified through **controlled methods**.

📌 **Why is Encapsulation Important?**
   - **Prevents accidental modifications** (data corruption).
   - **Restricts access** to sensitive data.
   - **Makes code more maintainable** by centralizing data management.

📌 **How to Implement Encapsulation?**
   - Declare **attributes as `private`** (cannot be accessed directly).
   - Provide **`public` methods** (getters/setters) for controlled access.
   - Use **validation** in setters to enforce rules.

📌 **Example: Bank Account Class**
   - The balance should **not** be directly modified.
   - The class provides `deposit()` and `withdraw()` methods.
*/
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;  // Private attribute: cannot be accessed directly

public:
    // Constructor to initialize balance
    BankAccount(double initialBalance) {
        if (initialBalance < 0) {
            cout << "Error: Initial balance cannot be negative. Setting to 0." << endl;
            balance = 0;
        } else {
            balance = initialBalance;
        }
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Error: Deposit amount must be positive." << endl;
        }
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Error: Insufficient funds or invalid amount." << endl;
        }
    }

    // Public method to check balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount myAccount(100);  // Create account with $100

    myAccount.deposit(50);       // Valid deposit
    myAccount.withdraw(30);      // Valid withdrawal
    myAccount.withdraw(200);     // Invalid withdrawal (not enough balance)

    cout << "Final balance: $" << myAccount.getBalance() << endl;

    return 0;
}