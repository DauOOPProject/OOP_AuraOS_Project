#ifndef PRICING_STRATEGY_H
#define PRICING_STRATEGY_H

#include "../models/Product.h"

/* ===== STRATEGY INTERFACE ===== */
class PricingStrategy {
public:
    virtual double calculatePrice(Product* p) = 0;
    virtual ~PricingStrategy() {}
};

#endif