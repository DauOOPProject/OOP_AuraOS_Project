#ifndef REFUND_COMMAND_H
#define REFUND_COMMAND_H

#include "Command.h"
#include <iostream>
using namespace std;

/* ===== REFUND COMMAND ===== */
class RefundCommand : public Command {
public:
    void execute() override {
        cout << "Refund processed successfully\n";
    }
};

#endif