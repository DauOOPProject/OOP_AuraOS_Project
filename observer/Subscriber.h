#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
using namespace std;

/* ===== OBSERVER INTERFACE ===== */
class Subscriber {
public:
    virtual void update(string event) = 0;
    virtual ~Subscriber() {}
};

#endif