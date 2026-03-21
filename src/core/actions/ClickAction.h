#ifndef CLICKACTION_H
#define CLICKACTION_H

#include "core/interfaces/IAction.h"

class ClickAction : public IAction {
public:
    ClickAction() = default;
    ~ClickAction() override = default;

    // Executa o clique físico no sistema operacional
    void execute() override;
};

#endif // CLICKACTION_H