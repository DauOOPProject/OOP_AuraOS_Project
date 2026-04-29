#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
private:
    double balance;

public:
    User(double initialBalance = 500) {
        balance = initialBalance;
    }

    double getBalance() {
        return balance;
    }

    bool deduct(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void addBalance(double amount) {
        balance += amount;
    }

    void setBalance(double b) {
        balance = b;
        
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }

};

#endif