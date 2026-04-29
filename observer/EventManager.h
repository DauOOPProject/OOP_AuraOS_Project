#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <vector>
#include <string>
using namespace std;

/* ===== INCLUDE DEPENDENCY ===== */
#include "Subscriber.h"

/* ===== EVENT MANAGER ===== */
class EventManager {
private:
    vector<Subscriber*> subscribers;

public:
    /* Subscribe to events */
    void subscribe(Subscriber* s) {
        subscribers.push_back(s);
    }

    /* Notify all subscribers */
    void notify(string event) {
        for (auto s : subscribers) {
            s->update(event);
        }
    }
};

#endif