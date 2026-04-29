#ifndef ACTIVE_STATE_H
#define ACTIVE_STATE_H

#include "KioskState.h"
using namespace std;

class ActiveState : public KioskState {
public:
    int getPurchaseLimit(string productName) override;
};

#endif