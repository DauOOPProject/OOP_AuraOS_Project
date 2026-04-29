#ifndef CENTRAL_REGISTRY_H
#define CENTRAL_REGISTRY_H

#include <iostream>
using namespace std;

/* ===== SINGLETON CLASS ===== */
class CentralRegistry {
private:
    static CentralRegistry* instance;

    /* Private Constructor (IMPORTANT) */
    CentralRegistry() {}

public:
    /* Prevent Copy */
    CentralRegistry(const CentralRegistry&) = delete;
    void operator=(const CentralRegistry&) = delete;

    /* Get Instance */
    static CentralRegistry* getInstance() {
        if (instance == nullptr) {
            instance = new CentralRegistry();
        }
        return instance;
    }

    /* System Info */
    void showSystemInfo() {
        cout << "Central Registry Active - System Initialized\n";
    }

    /* Example Config */
    void logEvent(string msg) {
        cout << "[LOG]: " << msg << endl;
    }
};

/* Static Initialization */
CentralRegistry* CentralRegistry::instance = nullptr;

#endif