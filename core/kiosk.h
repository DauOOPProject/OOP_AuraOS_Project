#ifndef KIOSK_H
#define KIOSK_H

#include <string>
using namespace std;

/* ===== INCLUDE DEPENDENCIES ===== */
#include "../inventory/Inventory.h"
#include "../pricing/PricingStrategy.h"
#include "../state/KioskState.h"
#include "../payment/Payment.h"
#include "../observer/EventManager.h"

/* ===== KIOSK CLASS ===== */
class Kiosk {
private:
    Inventory inventory;
    PricingStrategy* pricingStrategy;
    KioskState* state;
    Payment payment;
    EventManager* eventManager;

public:
    Kiosk(PricingStrategy* ps, KioskState* st);

    void addProduct(Product p);
    void showProducts();
    void purchase(string productName);

    void setPricingStrategy(PricingStrategy* ps);
    void setState(KioskState* st);

    void setEventManager(EventManager* em);
    
    void purchase(string productName, User& user, int qty);

    /* 🔥 NEW (FOR PERSISTENCE) */
    Inventory& getInventory();
};

#endif