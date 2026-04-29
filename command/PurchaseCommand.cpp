#include "PurchaseCommand.h"
#include "../core/Kiosk.h"

PurchaseCommand::PurchaseCommand(Kiosk* k, string name, User& u, int q)
    : kiosk(k), productName(name), user(u), qty(q) {}

void PurchaseCommand::execute() {
    kiosk->purchase(productName, user, qty);
}