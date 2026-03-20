#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include "core/interfaces/IAction.h" // Aponta para a pasta core

class IStrategy {
public:
    virtual ~IStrategy() = default;
    virtual void setAction(IAction* action) = 0;
    virtual void execute() = 0;
};

#endif