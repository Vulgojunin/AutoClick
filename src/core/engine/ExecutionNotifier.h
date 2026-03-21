#ifndef EXECUTIONNOTIFIER_H
#define EXECUTIONNOTIFIER_H

#include <vector>
#include <algorithm>
#include "core/interfaces/IControllerObserver.h"

class ExecutionNotifier {
private:
    std::vector<IControllerObserver*> m_observers;

public:
    void addObserver(IControllerObserver* obs) {
        if (obs && std::find(m_observers.begin(), m_observers.end(), obs) == m_observers.end()) {
            m_observers.push_back(obs);
        }
    }

    void removeObserver(IControllerObserver* obs) {
        m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), obs), m_observers.end());
    }

    void notifyStarted() {
        for (auto observer : m_observers) {
            if (observer) observer->onExecutionStarted();
        }
    }

    void notifyStopped() {
        for (auto observer : m_observers) {
            if (observer) observer->onExecutionStopped();
        }
    }
};

#endif // EXECUTIONNOTIFIER_H