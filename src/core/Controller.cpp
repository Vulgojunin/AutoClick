#include "Controller.h"

Controller::Controller() : m_engine(std::make_unique<Engine>()) {}
Controller::~Controller() {}

void Controller::registerObserver(IControllerObserver* observer) {
    if (observer) m_observers.push_back(observer);
}

void Controller::notifyStatus(Status s) {
    for (auto observer : m_observers) {
        observer->onStatusChanged(s);
    }
}

void Controller::requestStart() {
    m_engine->start();
    m_isRunning = true;
    notifyStatus(Status::Running);
}

void Controller::requestStop() {
    m_engine->stop();
    m_isRunning = false;
    notifyStatus(Status::Idle);
}

void Controller::toggleExecution() {
    if (m_isRunning) requestStop();
    else requestStart();
}

void Controller::updateDelay(int ms) {
    m_engine->setDelay(ms);
}