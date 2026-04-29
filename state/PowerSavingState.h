#ifndef POWER_SAVING_STATE_H
#define POWER_SAVING_STATE_H

#include "KioskState.h"
#include <iostream>
using namespace std;

/* ===== POWER SAVING STATE ===== */
class PowerSavingState : public KioskState {
public:
    int getPurchaseLimit(string productName) override;
};

#endif