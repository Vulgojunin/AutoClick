#include "controller/Controller.h"
#include "application/use_cases/StartClickingUseCase.h"
#include "application/use_cases/StopClickingUseCase.h"

Controller::Controller(Engine* engine) : m_engine(engine) {}

void Controller::handleCommand(AppCommand cmd, const CommandData& data) {
    if (cmd == AppCommand::StartClicking) {
        
        // Quando a Engine parar sozinha (atingiu o limite de cliques), ela chama isso:
        m_engine->setAutoStopCallback([this]() {
            m_notifier.notifyStopped();
        });

        StartClickingUseCase useCase(m_engine);
        m_notifier.notifyStarted();
        useCase.execute(data);
    } 
    else if (cmd == AppCommand::StopClicking) {
        StopClickingUseCase useCase(m_engine);
        useCase.execute();
        m_notifier.notifyStopped();
    }
}

void Controller::subscribe(IControllerObserver* obs) {
    m_notifier.addObserver(obs);
}

void Controller::unsubscribe(IControllerObserver* obs) {
    m_notifier.removeObserver(obs);
}