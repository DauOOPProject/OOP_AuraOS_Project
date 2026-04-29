#ifndef STANDARD_PRICING_H
#define STANDARD_PRICING_H

#include "PricingStrategy.h"
#include <iostream>
using namespace std;

/* ===== STANDARD PRICING ===== */
class StandardPricing : public PricingStrategy {
public:
    double calculatePrice(Product* p) override {
        cout << "Using STANDARD pricing\n";
        return p->price;
    }
};

#endif