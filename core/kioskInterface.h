#ifndef KIOSK_INTERFACE_H
#define KIOSK_INTERFACE_H

#include <string>
using namespace std;

/* ===== INCLUDE DEPENDENCY ===== */
#include "Kiosk.h"
#include "../models/Product.h"

/* ===== FACADE CLASS ===== */
class KioskInterface {
private:
    Kiosk* kiosk;

public:
    /* Constructor */
    KioskInterface(Kiosk* k) {
        kiosk = k;
    }

    /* ===== EXPOSED OPERATIONS ===== */

    void purchaseItem(string productName) {
        kiosk->purchase(productName);
    }

    void refundTransaction() {
        cout << "Refund feature not implemented yet\n";
    }

    void runDiagnostics() {
        cout << "Running system diagnostics...\n";
    }

    void restockInventory(Product p) {
        kiosk->addProduct(p);
        cout << "Product restocked successfully\n";
    }

    void showProducts() {
        kiosk->showProducts();
    }
};

#endif