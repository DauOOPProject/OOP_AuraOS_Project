#include "Inventory.h"
#include <iostream>
using namespace std;

/* ===== ADD PRODUCT ===== */
void Inventory::addProduct(Product p) {
        for (auto &prod : products) {
        if (prod.name == p.name) {
            prod.quantity += p.quantity;

            // Optional: update price if changed
            prod.price = p.price;

            return;
        }
    }

    products.push_back(p);
}

/* ===== SHOW PRODUCTS ===== */
void Inventory::showProducts() {
    cout << "\nAvailable Products:\n";
    for (auto &p : products) {
        cout << p.name 
             << " | Price: " << p.price 
             << " | Quantity: " << p.quantity << endl;
    }
}

/* ===== GET PRODUCT ===== */
Product* Inventory::getProduct(string name) {
    for (auto &p : products) {
        if (p.name == name) {
            return &p;
        }
    }
    return nullptr;
}

/* ===== GET ALL PRODUCTS ===== */
vector<Product>& Inventory::getAllProducts() {
    return products;
}

/* ===== SET PRODUCTS (LOAD FROM FILE) ===== */
void Inventory::setProducts(vector<Product> loadedProducts) {
    products = loadedProducts;
}