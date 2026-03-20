#include "Controller.h"
#include "actions/ClickAction.h"       // Sem ../ pois o CMake lê a partir de 'src'
#include "strategies/FixedStrategy.h"  // Sem ../

Controller::Controller() : m_engine(std::make_unique<Engine>()) {
    m_registry.registerAction("Esquerdo", std::make_unique<LeftClickAction>());
    m_registry.registerAction("Direito", std::make_unique<RightClickAction>());
    m_registry.registerStrategy("Fixo", std::make_unique<FixedStrategy>());

    selectAction("Esquerdo");
    selectStrategy("Fixo");
}

// ... restante do código igual ao anterior

Controller::~Controller() {}

void Controller::selectAction(const std::string& name) {
    m_currentAction = m_registry.getAction(name);
    if (m_currentStrategy && m_currentAction) {
        m_currentStrategy->setAction(m_currentAction);
    }
}

void Controller::selectStrategy(const std::string& name) {
    m_currentStrategy = m_registry.getStrategy(name);
    if (m_currentStrategy && m_currentAction) {
        m_currentStrategy->setAction(m_currentAction);
    }
}

std::vector<std::string> Controller::getAvailableActions() const {
    return m_registry.getActionNames();
}

std::vector<std::string> Controller::getAvailableStrategies() const {
    return m_registry.getStrategyNames();
}

void Controller::requestStart() {
    if (m_currentStrategy && !m_isRunning) {
        m_engine->start();
        m_isRunning = true;
        notifyStatus(Status::Running);
    }
}

void Controller::requestStop() {
    if (m_isRunning) {
        m_engine->stop();
        m_isRunning = false;
        notifyStatus(Status::Idle);
    }
}

void Controller::toggleExecution() {
    if (m_isRunning) requestStop();
    else requestStart();
}

void Controller::updateDelay(int ms) {
    m_engine->setDelay(ms);
}

void Controller::registerObserver(IControllerObserver* observer) {
    if (observer) m_observers.push_back(observer);
}

void Controller::notifyStatus(Status s) {
    for (auto obs : m_observers) obs->onStatusChanged(s);
}