#ifndef EMERGENCY_PRICING_H
#define EMERGENCY_PRICING_H

#include "PricingStrategy.h"
#include <iostream>
using namespace std;

/* ===== EMERGENCY PRICING ===== */
class EmergencyPricing : public PricingStrategy {
public:
    double calculatePrice(Product* p) override {
        cout << "Using EMERGENCY pricing (1.5x)\n";
        return p->price * 1.5;
    }
};

#endif