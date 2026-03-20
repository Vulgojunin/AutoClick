#include "Registry.h"

void Registry::registerAction(const std::string& name, std::unique_ptr<IAction> action) {
    m_actions[name] = std::move(action);
}

void Registry::registerStrategy(const std::string& name, std::unique_ptr<IStrategy> strategy) {
    m_strategies[name] = std::move(strategy);
}

IAction* Registry::getAction(const std::string& name) {
    if (m_actions.find(name) != m_actions.end()) {
        return m_actions[name].get();
    }
    return nullptr;
}

IStrategy* Registry::getStrategy(const std::string& name) {
    if (m_strategies.find(name) != m_strategies.end()) {
        return m_strategies[name].get();
    }
    return nullptr;
}

std::vector<std::string> Registry::getActionNames() const {
    std::vector<std::string> names;
    for (auto const& [name, action] : m_actions) names.push_back(name);
    return names;
}

std::vector<std::string> Registry::getStrategyNames() const {
    std::vector<std::string> names;
    for (auto const& [name, strategy] : m_strategies) names.push_back(name);
    return names;
}