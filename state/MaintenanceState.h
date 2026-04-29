#ifndef MAINTENANCE_STATE_H
#define MAINTENANCE_STATE_H

#include "KioskState.h"
using namespace std;

class MaintenanceState : public KioskState {
public:
    int getPurchaseLimit(string productName) override;
};

#endif