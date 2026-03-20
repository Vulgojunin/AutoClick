#ifndef CLICKACTION_H
#define CLICKACTION_H

#include "interfaces/IAction.h"

enum class MouseButton { Left, Right, Middle };
enum class ClickType { Single, Double, Hold };

class ClickAction : public IAction {
private:
    MouseButton button;
    ClickType type;

public:
    ClickAction(MouseButton b = MouseButton::Left, ClickType t = ClickType::Single);
    
    // Implementação do contrato
    void execute() override;

    // Setters para mudar o comportamento dinamicamente
    void setButton(MouseButton b) { button = b; }
    void setType(ClickType t) { type = t; }
};

#endif