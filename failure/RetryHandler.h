#ifndef RETRY_HANDLER_H
#define RETRY_HANDLER_H

#include "FailureHandler.h"
#include <iostream>
using namespace std;

/* ===== RETRY HANDLER ===== */
class RetryHandler : public FailureHandler {
public:
    void handle() override {
        cout << "Retrying operation...\n";

        // Simulate retry failure → pass to next
        if (next) {
            next->handle();
        }
    }
};

#endif