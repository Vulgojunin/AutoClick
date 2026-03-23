#ifndef CLICKACTION_H
#define CLICKACTION_H

#include "core/interfaces/IAction.h"
#include "core/CoreTypes.h" // Necessário para conhecer o enum ActionType

class ClickAction : public IAction {
public:
    // Construtor agora exige a injeção do tipo de clique
    explicit ClickAction(ActionType type);
    ~ClickAction() override = default;

    // Executa o clique físico no sistema operacional
    void execute() override;

private:
    ActionType m_type; // Armazena a decisão (LeftClick ou RightClick)
};

#endif // CLICKACTION_H