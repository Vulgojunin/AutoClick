#ifndef PLAYMACROACTION_H
#define PLAYMACROACTION_H

#include "core/interfaces/IAction.h"

class PlayMacroAction : public IAction {
public:
    PlayMacroAction() = default;
    ~PlayMacroAction() override = default;

    void execute() override;
};

#endif // PLAYMACROACTION_H