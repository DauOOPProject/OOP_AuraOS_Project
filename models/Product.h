#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

/* ===== PRODUCT CLASS ===== */
class Product {
public:
    string name;
    double price;
    int quantity;

    /* Constructor */
    Product(string n = "", double p = 0.0, int q = 0);
};

#endif