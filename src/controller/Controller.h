#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <string>

// Agora o compilador busca a partir de 'src/', então o caminho abaixo é absoluto dentro do projeto
#include "core/engine/Engine.h"
#include "core/engine/ExecutionNotifier.h"
#include "application/use_cases/AppTypes.h"
#include "application/use_cases/AppCommand.h"

class Controller {
private:
    Engine m_engine;
    ExecutionNotifier m_notifier;

public:
    Controller() = default;
    void handleCommand(AppCommand cmd, const CommandData& data);
    void subscribe(IControllerObserver* obs);
    std::vector<std::string> getAvailableActions() const;
};

#endif