#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include <fstream>
#include <string>
#include<iostream>
using namespace std;

class TransactionManager {
public:

    static void log(string product, double price) {
        ofstream file("transactions.csv", ios::app);

        file << product << "," << price << "\n";

        file.close();
    }

    static void showHistory() {
        ifstream file("transactions.csv");
        string line;

        cout << "\nTransaction History:\n";

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }
};

#endif