#include "EmergencyState.h"

int EmergencyState::getPurchaseLimit(string productName) {
    if (productName == "Water" || productName == "Milk")
        return 2;
    return 1;
}