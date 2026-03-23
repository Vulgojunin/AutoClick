#ifndef ACTIONREGISTRY_H
#define ACTIONREGISTRY_H

#include <memory>
#include "core/interfaces/IAction.h"
#include "core/actions/ClickAction.h"
#include "core/actions/PlayMacroAction.h" // Inclui a classe nova
#include "core/CoreTypes.h"

class ActionRegistry {
public:
    static std::unique_ptr<IAction> create(ActionType type) {
        switch (type) {
            case ActionType::LeftClick:
            case ActionType::RightClick: 
                return std::make_unique<ClickAction>(type); 
            case ActionType::Macro: 
                return std::make_unique<PlayMacroAction>(); // Retorna a Macro
            case ActionType::None:
            default:
                return nullptr;
        }
    }
};

#endif // ACTIONREGISTRY_H