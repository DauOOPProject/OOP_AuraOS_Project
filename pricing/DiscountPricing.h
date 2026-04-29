#ifndef DISCOUNT_PRICING_H
#define DISCOUNT_PRICING_H

#include "PricingStrategy.h"
#include <iostream>
using namespace std;

/* ===== DISCOUNT PRICING ===== */
class DiscountPricing : public PricingStrategy {
public:
    double calculatePrice(Product* p) override {
        cout << "Using DISCOUNT pricing (20% off)\n";
        return p->price * 0.8;
    }
};

#endif