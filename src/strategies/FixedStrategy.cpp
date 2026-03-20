#include "FixedStrategy.h"

void FixedStrategy::setAction(IAction* action) {
    m_currentAction = action;
}

void FixedStrategy::execute() {
    // Só executa se a ação existir (Segurança contra crash)
    if (m_currentAction) {
        m_currentAction->execute();
    }
}