#ifndef REGISTRY_H
#define REGISTRY_H

#include <map>
#include <string>
#include <memory>
#include <vector>
#include "core/interfaces/IAction.h"       // Caminho completo
#include "strategies/interfaces/IStrategy.h" // Caminho completo corrigido

class Registry {
public:
    Registry() = default;
    
    void registerAction(const std::string& name, std::unique_ptr<IAction> action);
    void registerStrategy(const std::string& name, std::unique_ptr<IStrategy> strategy);

    IAction* getAction(const std::string& name);
    IStrategy* getStrategy(const std::string& name);

    std::vector<std::string> getActionNames() const;
    std::vector<std::string> getStrategyNames() const;

private:
    std::map<std::string, std::unique_ptr<IAction>> m_actions;
    std::map<std::string, std::unique_ptr<IStrategy>> m_strategies;
};

#endif