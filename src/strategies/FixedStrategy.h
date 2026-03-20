#ifndef FIXEDSTRATEGY_H
#define FIXEDSTRATEGY_H

#include "interfaces/IStrategy.h"
#include "IAction.h"

class FixedStrategy : public IStrategy {
public:
    FixedStrategy() = default;

    // Cumprindo as promessas da interface
    void setAction(IAction* action) override;
    void execute() override;

private:
    IAction* m_currentAction = nullptr; // Usando padrão m_ para membros
};

#endif