#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
using namespace std;

/* ===== INCLUDE DEPENDENCIES ===== */
#include "../models/Product.h"

/* ===== INVENTORY CLASS ===== */
class Inventory {
private:
    vector<Product> products;

public:
    /* Core Functions */
    void addProduct(Product p);
    void showProducts();
    Product* getProduct(string name);

    /* Persistence Support */
    vector<Product>& getAllProducts();
    void setProducts(vector<Product> loadedProducts);
};

#endif