#ifndef KIOSK_STATE_H
#define KIOSK_STATE_H

#include <string>
using namespace std;

class KioskState {
public:
    virtual int getPurchaseLimit(string productName) = 0;
    virtual ~KioskState() {}
};

#endif