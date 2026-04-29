#ifndef COMMAND_H
#define COMMAND_H

/* ===== COMMAND INTERFACE ===== */
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

#endif