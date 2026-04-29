#ifndef MONITORING_SYSTEM_H
#define MONITORING_SYSTEM_H

#include "Subscriber.h"
#include <iostream>
using namespace std;

/* ===== CONCRETE OBSERVER ===== */
class MonitoringSystem : public Subscriber {
public:
    void update(string event) override {
        cout << "Monitoring Alert: " << event << endl;
    }
};

#endif