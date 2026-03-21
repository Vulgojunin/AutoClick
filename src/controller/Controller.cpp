#include "Controller.h"
#include "application/use_cases/StartClickingUseCase.h"
#include "application/use_cases/StopClickingUseCase.h"

void Controller::handleCommand(AppCommand cmd, const CommandData& data) {
    if (cmd == AppCommand::StartClicking) {
        StartClickingUseCase useCase(&m_engine);
        useCase.execute(data);
        m_notifier.notifyStarted();
    } 
    else if (cmd == AppCommand::StopClicking) {
        StopClickingUseCase useCase(&m_engine);
        useCase.execute();
        m_notifier.notifyStopped();
    }
}

void Controller::subscribe(IControllerObserver* obs) {
    m_notifier.addObserver(obs);
}

std::vector<std::string> Controller::getAvailableActions() const {
    return { "Clique Esquerdo", "Clique Direito" };
}