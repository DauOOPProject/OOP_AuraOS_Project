#ifndef EMERGENCY_STATE_H
#define EMERGENCY_STATE_H

#include "KioskState.h"
using namespace std;

class EmergencyState : public KioskState {
public:
    int getPurchaseLimit(string productName) override;
};

#endif