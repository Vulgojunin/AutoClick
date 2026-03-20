#ifndef FIXEDSTRATEGY_H
#define FIXEDSTRATEGY_H

#include "strategies/interfaces/IStrategy.h"
#include "core/interfaces/IAction.h"

class FixedStrategy : public IStrategy {
public:
    FixedStrategy() = default;
    void setAction(IAction* action) override;
    void execute() override;

private:
    IAction* m_currentAction = nullptr;
};

#endif