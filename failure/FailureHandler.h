#ifndef FAILURE_HANDLER_H
#define FAILURE_HANDLER_H

/* ===== BASE HANDLER ===== */
class FailureHandler {
protected:
    FailureHandler* next;

public:
    FailureHandler() {
        next = nullptr;
    }

    void setNext(FailureHandler* n) {
        next = n;
    }

    virtual void handle() {
        if (next) {
            next->handle();
        }
    }

    virtual ~FailureHandler() {}
};

#endif