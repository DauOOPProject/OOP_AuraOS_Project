#ifndef PURCHASE_COMMAND_H
#define PURCHASE_COMMAND_H

#include "Command.h"
#include <string>
using namespace std;

class Kiosk;
class User;

class PurchaseCommand : public Command {
private:
    Kiosk* kiosk;
    string productName;
    User& user;
    int qty;

public:
    PurchaseCommand(Kiosk* k, string name, User& u, int q);
    void execute() override;
};

#endif