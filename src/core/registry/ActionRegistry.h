#ifndef ACTIONREGISTRY_H
#define ACTIONREGISTRY_H

#include <memory>
#include "core/interfaces/IAction.h"
#include "core/actions/ClickAction.h" // Mantendo sua classe atual
#include "core/CoreTypes.h"

class ActionRegistry {
public:
    static std::unique_ptr<IAction> create(ActionType type) {
        switch (type) {
            case ActionType::LeftClick:
            case ActionType::RightClick: 
                return std::make_unique<ClickAction>(); 
            case ActionType::None:
            default:
                return nullptr; // Evita instanciar lixo na memória
        }
    }
};

#endif // ACTIONREGISTRY_H