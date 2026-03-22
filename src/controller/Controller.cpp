#include "Controller.h"
#include "application/use_cases/StartClickingUseCase.h"
#include "application/use_cases/StopClickingUseCase.h"

Controller::Controller(Engine* engine) : m_engine(engine) {}

void Controller::handleCommand(AppCommand cmd, const CommandData& data) {
    if (cmd == AppCommand::StartClicking) {
        // Criamos o UseCase, passamos a Engine e o Notificador
        StartClickingUseCase useCase(m_engine);
        // Notificamos que vai começar
        m_notifier.notifyStarted();
        useCase.execute(data);
    } 
    else if (cmd == AppCommand::StopClicking) {
        StopClickingUseCase useCase(m_engine);
        useCase.execute();
        // Notificamos que parou
        m_notifier.notifyStopped();
    }
}

void Controller::subscribe(IControllerObserver* obs) {
    m_notifier.addObserver(obs);
}

// CORREÇÃO: Função específica para remover o observador
void Controller::unsubscribe(IControllerObserver* obs) {
    m_notifier.removeObserver(obs);
}