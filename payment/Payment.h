#ifndef PAYMENT_H
#define PAYMENT_H

#include "../models/User.h"

class Payment {
public:
    bool processPayment(double amount, User& user);
};

#endif