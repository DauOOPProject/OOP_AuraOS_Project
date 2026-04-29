#ifndef KIOSK_FACTORY_H
#define KIOSK_FACTORY_H

#include <string>
using namespace std;

/* ===== INCLUDE DEPENDENCIES ===== */
#include "../core/Kiosk.h"
#include "../pricing/StandardPricing.h"
#include "../pricing/EmergencyPricing.h"
#include "../state/ActiveState.h"
#include "../state/EmergencyState.h"

/* ===== FACTORY CLASS ===== */
class KioskFactory {
public:

    static Kiosk* createKiosk(string type) {

        if (type == "Pharmacy") {
            cout << "Creating Pharmacy Kiosk...\n";
            return new Kiosk(new StandardPricing(), new ActiveState());
        }

        else if (type == "Food") {
            cout << "Creating Food Kiosk...\n";
            return new Kiosk(new StandardPricing(), new ActiveState());
        }

        else if (type == "Emergency") {
            cout << "Creating Emergency Relief Kiosk...\n";
            return new Kiosk(new EmergencyPricing(), new EmergencyState());
        }

        else {
            cout << "Invalid kiosk type!\n";
            return nullptr;
        }
    }
};

#endif