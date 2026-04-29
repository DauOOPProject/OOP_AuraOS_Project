#ifndef RECALIBRATION_HANDLER_H
#define RECALIBRATION_HANDLER_H

#include "FailureHandler.h"
#include <iostream>
using namespace std;

/* ===== RECALIBRATION HANDLER ===== */
class RecalibrationHandler : public FailureHandler {
public:
    void handle() override {
        cout << "Recalibrating system...\n";

        // Simulate recalibration failure → pass to next
        if (next) {
            next->handle();
        }
    }
};

#endif