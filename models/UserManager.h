#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <fstream>
#include <iostream>
#include "User.h"
using namespace std;

class UserManager {
public:

    /* ===== SAVE USER ===== */
    static void save(User& user) {
        ofstream file("user.csv");
        file << user.getBalance();
        file.close();
    }

    /* ===== LOAD USER ===== */
    static User load() {
        ifstream file("user.csv");

        double balance = 200; // default

        if (file.good()) {
            file >> balance;
        }

        file.close();

        return User(balance);
    }
};

#endif