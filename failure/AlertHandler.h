#ifndef ALERT_HANDLER_H
#define ALERT_HANDLER_H

#include "FailureHandler.h"
#include <iostream>
using namespace std;

/* ===== ALERT HANDLER ===== */
class AlertHandler : public FailureHandler {
public:
    void handle() override {
        cout << "Alerting technician...\n";
    }
};

#endif