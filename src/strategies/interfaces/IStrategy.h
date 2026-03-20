#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include "IAction.h" // Agora a estratégia sabe o que é uma Ação

class IStrategy {
public:
    virtual ~IStrategy() = default;
    
    // Todas as estratégias precisam de uma ação e um método para rodar
    virtual void setAction(IAction* action) = 0;
    virtual void execute() = 0; 
};

#endif