#ifndef ACTIONREGISTRY_H
#define ACTIONREGISTRY_H

#include <memory>
#include "core/interfaces/IAction.h"
#include "core/actions/ClickAction.h" // Garante que a classe concreta seja conhecida
#include "application/use_cases/AppTypes.h"

class ActionRegistry {
public:
    // Cria a ação de execução (clique do mouse, etc)
    static std::unique_ptr<IAction> create(ActionType type) {
        switch (type) {
            case ActionType::LeftClick:
                // Por enquanto, usamos ClickAction para simular o clique esquerdo
                return std::make_unique<ClickAction>();

            case ActionType::RightClick:
                // Futuramente você pode criar a classe RightClickAction
                return std::make_unique<ClickAction>();

            default:
                return std::make_unique<ClickAction>();
        }
    }
};

#endif // ACTIONREGISTRY_H