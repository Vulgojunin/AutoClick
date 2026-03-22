#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include "application/use_cases/AppCommand.h"
#include "application/use_cases/AppTypes.h"
#include "core/engine/ExecutionNotifier.h"
#include "core/engine/Engine.h"
#include "core/interfaces/IControllerObserver.h"

class Controller {
public:
    explicit Controller(Engine* engine);
    
    // Processa as ordens vindas da UI
    void handleCommand(AppCommand cmd, const CommandData& data);

    // Gerenciamento de Observers (Ouvintes da UI)
    void subscribe(IControllerObserver* obs);
    void unsubscribe(IControllerObserver* obs); // CORRIGIDO: Agora com 'un'

private:
    Engine* m_engine;
    ExecutionNotifier m_notifier;
};

#endif // CONTROLLER_H