#include "Kiosk.h"
#include <iostream>
#include "../inventory/TransactionManager.h"

using namespace std;

/* ===== CONSTRUCTOR ===== */
Kiosk::Kiosk(PricingStrategy* ps, KioskState* st) {
    pricingStrategy = ps;
    state = st;
    eventManager = nullptr;
}

/* ===== ADD PRODUCT ===== */
void Kiosk::addProduct(Product p) {
    inventory.addProduct(p);
}

/* ===== SHOW PRODUCTS ===== */
void Kiosk::showProducts() {
    inventory.showProducts();
}

/* ===== GET INVENTORY ===== */
Inventory& Kiosk::getInventory() {
    return inventory;
}

/* ===== SET STATE ===== */
void Kiosk::setState(KioskState* st) {
    state = st;

    if (eventManager)
        eventManager->notify("StateChanged");
}

/* ===== SET PRICING ===== */
void Kiosk::setPricingStrategy(PricingStrategy* ps) {
    pricingStrategy = ps;
}

/* ===== SET EVENT MANAGER ===== */
void Kiosk::setEventManager(EventManager* em) {
    eventManager = em;
}

/* ===== PURCHASE ===== */
void Kiosk::purchase(string productName, User& user, int qty) {

    int limit = state->getPurchaseLimit(productName);

    if (limit == 0) {
        cout << "Purchases disabled in current mode!\n";
        return;
    }

    if (qty > limit) {
        cout << "Limit exceeded! Max allowed: " << limit << endl;
        return;
    }

    Product* p = inventory.getProduct(productName);

    if (!p || p->quantity < qty) {
        cout << "Not enough stock!\n";
        return;
    }

    double finalPrice = pricingStrategy->calculatePrice(p) * qty;

    cout << "Final Price: " << finalPrice << endl;

    bool success = payment.processPayment(finalPrice, user);

    if (success) {
        p->quantity -= qty;

        TransactionManager::log(p->name, finalPrice);

        cout << "Purchase successful!\n";

        if (eventManager)
            eventManager->notify("PurchaseSuccess");
    } else {
        cout << "Transaction failed!\n";
    }
}