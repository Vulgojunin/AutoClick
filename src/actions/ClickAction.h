#ifndef CLICKACTION_H
#define CLICKACTION_H

#include "core/interfaces/IAction.h"

class LeftClickAction : public IAction {
public:
    void execute() override;
};

class RightClickAction : public IAction {
public:
    void execute() override;
};

#endif