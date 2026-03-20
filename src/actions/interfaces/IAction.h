#ifndef IACTION_H
#define IACTION_H

class IAction {
public:
    virtual ~IAction() = default;
    virtual void execute() = 0;
};

#endif