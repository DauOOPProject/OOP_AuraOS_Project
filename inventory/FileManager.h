#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

/* ===== INCLUDE DEPENDENCY ===== */
#include "../models/Product.h"

/* ===== FILE MANAGER CLASS ===== */
class FileManager {
public:

    /* ===== SAVE INVENTORY TO CSV ===== */
    static void save(vector<Product>& products) {
        ofstream file("inventory.csv");

        for (auto &p : products) {
            file << p.name << ","
                 << p.price << ","
                 << p.quantity << "\n";
        }

        file.close();
    }

    /* ===== LOAD INVENTORY FROM CSV ===== */
    static vector<Product> load() {
        vector<Product> products;

        ifstream file("inventory.csv");
        string line;

        while (getline(file, line)) {
            stringstream ss(line);

            string name;
            double price;
            int quantity;

            getline(ss, name, ',');
            ss >> price;
            ss.ignore();
            ss >> quantity;

            products.push_back(Product(name, price, quantity));
        }

        file.close();
        return products;
    }
};

#endif